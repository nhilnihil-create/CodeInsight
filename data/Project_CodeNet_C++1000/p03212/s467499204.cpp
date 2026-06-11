#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

bool has_573(int64_t n) {
    bool has7 = false;
    bool has5 = false;
    bool has3 = false;
    while(!(has5 && has7 && has3) && n > 0) {
        int mod = n % 10; 
        if(mod == 3)
            has3 = true;
        if(mod == 5)
            has5 = true;
        if(mod == 7)
            has7 = true;
        n /= 10;
    }
    return has5 && has7 && has3;
}

int main() {
    int64_t N;
    cin >> N;

    queue<int64_t> q;
    q.push(0);

    int ret = 0;
    int64_t n = 0;
    while(n <= N) {
        if(has_573(n)) {
            ret++;
        }
        n = q.front();
        q.pop();
        q.push(n*10+3);
        q.push(n*10+5);
        q.push(n*10+7);
    }
    cout << ret << endl;

    return 0;
}
