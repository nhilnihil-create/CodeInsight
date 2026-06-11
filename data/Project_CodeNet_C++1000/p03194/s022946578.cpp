#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<int,int> P;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    ll n, p; cin >> n >> p;
    ll ans = 1LL;
    if(n==1) {
        cout << p << endl;
        return 0;
    }
    for(ll i=2; i*i<=p; i++) {
        int cnt = 0;
        if(p%i != 0) continue;
        while(p%i==0) p/=i,cnt++;
        rep(j, cnt/n) {
            ans *= i;
        }
    }
    print(ans);
}

