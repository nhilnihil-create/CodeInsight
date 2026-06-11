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
    vector<int> x(n);
    for(int i = 0;i < n;i ++) cin >> x.at(i);

    vector<int> y(n);
    for(int i = 0;i < n;i ++){
        y.at(i) = x.at(i);
    }
    sort(y.begin(),y.end());

    int a = y.at(n/2 - 1),b = y.at(n/2);

    for(int i = 0;i < n;i ++){
        if(x.at(i) >= b) cout << a << endl;
        else cout << b << endl;
    }
}