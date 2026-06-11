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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
	int T; cin >> T;
    while(T--){
        ll A,B,C,D; cin >> A >> B >> C >> D;
        if(A < B){cout << "No" << endl; continue;}
        if(D < B){cout << "No" << endl; continue;}
        if(C >= B){cout << "Yes" << endl; continue;}
        ll g = GCD(B,D);
        ll ans = B-g+A%g;
        cout << (ans <= C ? "Yes" : "No") << endl;
    }
}
   
