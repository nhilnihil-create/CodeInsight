#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
#define ALL(X) X.begin(), X.end()
using lint = long long;
template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main() {
    lint n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    std::vector<std::pair<lint, lint>> sushi;

    for (int i = 0; i < n; ++i) {
        lint t, d;
        scanf("%lld", &t);
        scanf("%lld", &d);

        sushi.emplace_back(d, t);
    }

    std::sort(ALL(sushi), std::greater<std::pair<lint, lint>>());

    std::set<lint> appear;
    std::multiset<lint> red;

    lint idx = 0;
    lint del_sum = 0;
    lint kind_num = 0;

    for (; idx < k; ++idx) {
        auto cur_sushi = sushi[idx];
        lint cur_del = cur_sushi.first;
        lint cur_kind = cur_sushi.second;
        del_sum += cur_del;
        if (appear.find(cur_kind) == appear.end()) {
            appear.insert(cur_kind);
            kind_num++;
        }
        else {
            red.insert(cur_del);
        }
    }

    lint score = del_sum + kind_num*kind_num;

    for (; idx < n; ++idx) {
        auto cur_sushi = sushi[idx];
        lint cur_del = cur_sushi.first;
        lint cur_kind = cur_sushi.second;

        if (red.size() == 0) {
            break;
        }

        if (appear.find(cur_kind) == appear.end()) {
            del_sum -= *red.begin();
            del_sum += cur_del;
            red.erase(red.begin());

            appear.insert(cur_kind);
            kind_num++;

            score = std::max(score, del_sum + kind_num*kind_num);
        }
    }

    std::cout << score << "\n";


    return 0;
}
