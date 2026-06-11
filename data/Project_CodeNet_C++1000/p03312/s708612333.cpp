#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;


int main(){
    int N; cin >> N;
    vi A(N);
    vector<ll> s(N+1, 0);
    for(int i=0; i<N; i++){
        cin >> A[i];
        s[i+1]=s[i]+A[i];
    }
    ll res=LINF;
    for(int i=1; i<N-2; i++){
        auto it1=lower_bound(all(s), s[i+1]/2);
        auto it2=lower_bound(all(s), s[i+1]+(s[N]-s[i+1])/2);
        ll P1=*it1, P2= it1 == s.begin()?LINF:*(--it1);
        ll Q1=s[i+1]-P1, Q2=s[i+1]-P2;
        ll R1=*it2-s[i+1], R2= it2 == s.begin()?LINF:*(--it2)-s[i+1];
        ll S1=s[N]-R1-s[i+1], S2=s[N]-R2-s[i+1];
        ll maxi=max(P1, max(Q1, max(R1, S1)));
        ll mini=min(P1, min(Q1, min(R1, S1)));
        res=min(res, maxi-mini);
        maxi=max(P1, max(Q1, max(R2, S2)));
        mini=min(P1, min(Q1, min(R2, S2)));
        res=min(res, maxi-mini);
        maxi=max(P2, max(Q2, max(R1, S1)));
        mini=min(P2, min(Q2, min(R1, S1)));
        res=min(res, maxi-mini);
        maxi=max(P2, max(Q2, max(R2, S2)));
        mini=min(P2, min(Q2, min(R2, S2)));
        //cout << P1 << " " << Q1 << " " << R1 << " " << S1 << endl;
        //cout << P2 << " " << Q2 << " " << R2 << " " << S2 << endl;
        res=min(res, maxi-mini);
    }
    cout << res << endl;
    return 0;
}