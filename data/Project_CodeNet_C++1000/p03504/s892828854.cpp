#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;

int main(void) {
    int N, C;
    cin >> N >> C;
    vector< tuple<int,int,int> > program(N);
    for(int i=0; i<N; i++) {
        cin >> get<0>(program[i]) >> get<1>(program[i]) >> get<2>(program[i]);
    }

    sort(program.begin(), program.end(), [](auto &lhs, auto &rhs) {return (get<2>(lhs) == get<2>(rhs)) ? get<1>(lhs) < get<1>(rhs) : get<2>(lhs) < get<2>(rhs);});
    for(int i=1; i<N; i++) {
        if(get<2>(program[i]) == get<2>(program[i-1]) && get<1>(program[i-1]) == get<0>(program[i])) {
            get<0>(program[i]) = get<0>(program[i-1]);
            get<1>(program[i-1]) = get<0>(program[i-1]) - 1;
        }
    }

    vector<int> time(100010);
    for(auto e: program) {
        ++time[get<0>(e) - 1];
        --time[get<1>(e)];
    }
    partial_sum(time.begin(), time.end(), time.begin());

    cout << (*max_element(time.begin(), time.end())) << endl;
    return 0;
}
