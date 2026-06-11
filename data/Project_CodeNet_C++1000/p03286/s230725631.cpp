#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 1e+9
const ll MOD = 1000000007;

int main(){
    ll n; cin >> n;
    if(n == 0) {cout << 0 << endl; return 0;}
    if(n == 1) {cout << 1 << endl; return 0;}
    vector<int> ans;
    while(n != 0){
        if(n % 2 != 0) {
            ans.pb(1);
            n -= 1;
        }
        else ans.pb(0);
        n /= (-2);
    }
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];    
}