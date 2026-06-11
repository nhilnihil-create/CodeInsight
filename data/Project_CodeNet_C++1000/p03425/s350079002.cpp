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
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> count(6);
    for(int i = 0;i < n;i ++){
        string s;
        cin >> s;
        if(s.at(0) == 'M') count.at(1) ++;
        if(s.at(0) == 'A') count.at(2) ++;
        if(s.at(0) == 'R') count.at(3) ++;
        if(s.at(0) == 'C') count.at(4) ++;
        if(s.at(0) == 'H') count.at(5) ++;
    }

    int ans = 0;
    vector<int> select(6);
    int sum;
    while(select.at(0) == 0){
        select.at(5) ++;
        for(int i = 5;i > 0;i --){
            if(select.at(i) == 2){
                select.at(i) = 0;
                select.at(i-1) ++;
            }
        }

        sum = 0;
        for(int i = 0;i < 6;i ++) sum += select.at(i);
        if(sum == 3){
            int keisan = 1;
            for(int i = 1;i < 6;i ++){
                if(select.at(i) == 1)keisan *= count.at(i);
            }
            ans += keisan;
        }
    }

    cout << ans << endl;
}