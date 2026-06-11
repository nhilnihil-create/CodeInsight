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
    vector<int> b(n);
    for(int i = 0;i < n;i ++) cin >> b.at(i);

    for(int i = 0;i < n;i ++){
        if(b.at(i) > i+1){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> a(n),done(n);
    vector<int> count(n);

    for(int i = 0;i < n;i ++){
        count.at(i) = i+1 - b.at(i);
    }

    for(int i = n-1;i >= 0;i --){
        for(int j = n-1;j >= 0;j --){
            if(count.at(j) == 0 && done.at(j) == 0){
                a.at(i) = b.at(j);
                for(int k = j+1;k < n;k ++) count.at(k) --;
                done.at(j) = 1;
                break;
            }
        }
    }

    for(int i = 0;i < n;i ++){
        cout << a.at(i) << endl;
    }
}