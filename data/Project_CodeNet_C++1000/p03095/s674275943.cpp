#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=1, tmp=0;
char c;
map<char, ll> M;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> c;
        M[c]++;
    }
    for(map<char, ll>::iterator itr=M.begin();itr!=M.end();itr++) {
        pair<char, ll> p = *itr;
        ans *= p.second+1;
        ans %= 1000000007;
    }
    ans--;
    cout << ans << endl;
    return 0;
}