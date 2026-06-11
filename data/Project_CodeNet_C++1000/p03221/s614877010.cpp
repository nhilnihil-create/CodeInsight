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

    int n,m; cin >> n >> m;
    vector<int> p(m),y(m);
    for(int i = 0;i < m;i ++){
        cin >> p.at(i) >> y.at(i);
    }

    vector<vector<int> > a(n+1,vector<int>(0));
    for(int i = 0;i < m;i ++){
        a.at(p.at(i)).push_back(y.at(i));
    }

    for(int i = 0;i < n+1;i ++){
        sort(a.at(i).begin(),a.at(i).end());
    }

    for(int i = 0;i < m;i ++){
        cout << setw(6) << setfill('0') << p.at(i);

        auto iter = lower_bound(a.at(p.at(i)).begin(),a.at(p.at(i)).end(),y.at(i));
        cout << setw(6) << setfill('0') << iter - a.at(p.at(i)).begin() +1 << endl;

    }

    
}