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

    int k,a,b; cin >> k >> a >> b;
    if(b-a <= 2){
        cout << k+1 << endl;
        return 0;
    }

    int ans = 1;
    for(int i = 0;i < k;i ++){
        if(ans < a || i == k-1) ans ++;
        else{
            ans += b - a;
            i ++;
        }
    }

    cout << ans << endl;
}

