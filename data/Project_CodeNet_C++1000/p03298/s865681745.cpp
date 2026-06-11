#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A;
map<pair<string,ll>,ll> M;
string S;

void dfsmap(vector<ll> v, ll id) {
    if(id==N) {
        string Stmp;
        ll ct=0;
        for(int i=0;i<N;i++) {
            if(v[i]) {
                Stmp += S[i];
                ct++;
            }
        }
        for(int i=N-1;i>=0;i--) {
            if(v[i]==0) {
                Stmp += S[i];
            }
        }
        pair<string,ll> p = make_pair(Stmp,ct);
        M[p]++;
        return;
    }
    dfsmap(v, id+1);
    v[id] = 1;
    dfsmap(v, id+1);
}

void dfsref(vector<ll> v, ll id) {
    if(id==N) {
        string Stmp;
        ll ct=0;
        for(int i=0;i<N;i++) {
            if(v[i]) {
                Stmp += S[2*N-1-i];
                ct++;
            }
        }
        for(int i=N-1;i>=0;i--) {
            if(v[i]==0) {
                Stmp += S[2*N-1-i];
            }
        }
        pair<string,ll> p = make_pair(Stmp,ct);
        ans += M[p];
        return;
    }
    dfsref(v, id+1);
    v[id] = 1;
    dfsref(v, id+1);
}

signed main(){
    cin >> N >> S;
    vector<ll> vemp(N,0);
    dfsmap(vemp,0);
    dfsref(vemp,0);
    cout << ans << endl;
    return 0;
}