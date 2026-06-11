#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#define _GLIBCXX_DEBUG // check []
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,int> pii;
typedef pair<int64_t, int64_t> pII;

template<typename T>
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#define ps(arr) \
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

int count(string& str, string& sub) {
    int sz = sub.length();
    int cnt = 0;
    for(int i = 0; i < str.size()-(sz-1); i++) {
        if(str.substr(i, sz) == sub) cnt++;
    }
    return cnt;
}

int main(void) {
    int num;
    cin >> num;
    int sum = 0;
    int head_cnt = 0;
    int tail_cnt = 0;
    int cnt = 0;
    static string ab = "AB";
    for(int i = 0; i < num; i++) {
        string str;
        cin >> str;
        sum += count(str, ab);
        int flag = 0;
        if(str[0] == 'B') {
            flag = 1;
            head_cnt++;
        }
        if(*(str.end()-1) == 'A') {
            flag = 1;
            tail_cnt++;
        }
        cnt += flag;
    }
    debug("%d\n", sum);
    int bonus = max(cnt-1, 0);
    bonus = min(bonus, head_cnt);
    bonus = min(bonus, tail_cnt);
    cout << sum+bonus << endl;
    return 0;
}