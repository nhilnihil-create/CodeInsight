#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200001;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);
map<ll, ll> M;
signed main(){
    cin >> N;
    M[0]++;
    for(int i=1;i<=N;i++) {
        ll a;
        cin >> a;
        A[i] = A[i-1]+a;
        M[A[i]]++;
    }
    for(map<ll, ll>::iterator itr=M.begin();itr!=M.end();itr++) {
        pair<ll, ll> p = *itr;
        if(p.second>1) ans += p.second*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}