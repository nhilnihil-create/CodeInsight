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
    vector<int> a(n),b(n);
    for(int i = 0;i < n;i ++) cin >> a.at(i);
    for(int i = 0;i < n;i ++) cin >> b.at(i);

    int asum = 0, bsum = 0;
    for(int i = 0;i < n;i ++){
        asum += a.at(i);
        bsum += b.at(i);
    }

    if(asum < bsum){
        cout << -1 << endl;
        return 0;
    }

    vector<int> x(n);
    for(int i = 0;i < n;i ++) x.at(i) = a.at(i) - b.at(i);

    vector<int> y(n);

    sort(x.begin(),x.end());

    for(int i = 0;i < n;i ++) y.at(i) = x.at(i);


    int l = 0,r = n-1;
    
    while(x.at(l) < 0){
        int ido = min(abs(x.at(l)),x.at(r));
        x.at(l) += ido;
        x.at(r) -= ido;

        if(x.at(l) == 0) l ++;
        if(x.at(r) == 0) r --;
    }

    int ans = 0;

    for(int i = 0;i < n;i ++){
        if(x.at(i) != y.at(i)) ans ++;
    }

    cout << ans << endl;

}