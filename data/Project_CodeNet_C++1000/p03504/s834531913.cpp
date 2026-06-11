#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <map>
using program_type = std::pair<int32_t, int32_t>;
using programs_array_type = std::vector<program_type>;

void merge_consec_program(programs_array_type& per_ch, programs_array_type& global) {
    if (per_ch.empty()) return;

    std::sort(per_ch.begin(), per_ch.end());
    global.emplace_back(per_ch[0]);
    for (auto it = per_ch.begin()+1; it != per_ch.end(); it++) {
        //merge
        if (it->first == global.back().second) {
            (global.end() - 1) -> second = it->second;
        } else {
            global.emplace_back(*it);
        }
    }
}

int main(){
    int32_t N, C;
    std::cin >> N >> C;
    std::vector<programs_array_type> per_channel_program(C);
    programs_array_type global_program;
    
    for (int32_t i = 0; i < N; i++) {
        int32_t s, t, c;
        std::cin >> s >> t >> c;
        per_channel_program[c-1].push_back(std::make_pair(s,t));
    }

    //sort and merge
    for (int32_t c = 0; c < C; c++) {
        merge_consec_program(per_channel_program[c], global_program);
    }

    //sort global program
    std::sort(global_program.begin(), global_program.end());

    //Greedy
    std::vector<int32_t> last_program;
    for (auto program : global_program) {
        bool updated = false;
        for (int32_t i = 0; i < (int32_t)last_program.size(); i++) {
            if (last_program[i] < program.first) {
                last_program[i] = program.second;
                updated = true;
                break;
            }
        }
        if (!updated) last_program.push_back(program.second);
    }

    std::cout << last_program.size() << std::endl;
    return 0;
}
