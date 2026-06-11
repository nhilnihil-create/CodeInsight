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

int gcd(int c,int d){
    return d ? gcd(d, c % d) : c;
}



signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> d(n);
    for(int i = 0;i < n;i ++) cin >> d.at(i);
    int m; cin >> m;
    vector<int> t(m);
    for(int i = 0;i < m;i ++) cin >> t.at(i);

    if(n < m){
        cout << "NO" << endl;
        return 0;
    }

    sort(d.begin(),d.end());
    sort(t.begin(),t.end());

    int j = 0;
    for(int i = 0;i < m;i ++){
        for(;j < n;j ++){
            if(t.at(i) == d.at(j)){
                j ++;
                break;
            }
            if(j == n-1){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
}

