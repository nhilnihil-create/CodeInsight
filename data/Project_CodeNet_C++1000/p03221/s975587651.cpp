#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P =pair<ll,ll>;

int main() {
    ll N,M;
    cin >>N >>M;
    vector<vector<P>> pref(N);
    for(int i=0;i<M;i++){
        ll p,y;
        cin >>p >>y;
        --p;
        pref[p].push_back(P(y,i));
    }

    vector<P> ans(M);
    for(int i=0;i<N;i++){
        sort(pref[i].begin(),pref[i].end());
        for(int j=0;j<pref[i].size();j++){
            ans[pref[i][j].second] = P(i+1,j+1);
        }
    }

    for(int i=0;i<M;i++){
        printf("%06lld",ans[i].first);
        printf("%06lld",ans[i].second);
        cout << "\n";
    }



    return 0;
}