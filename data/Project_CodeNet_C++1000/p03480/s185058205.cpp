#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    string s; cin >> s;
    int n = s.size();
    int ans = INF;
    rep(i,n-1){
        if(s[i] != s[i+1]){
            ans = min(ans,max(i+1,n-i-1));
        }
    }
    if(ans == INF) cout << n << endl;
    else cout << ans << endl;
}

    

