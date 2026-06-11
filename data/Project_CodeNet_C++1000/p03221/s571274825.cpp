#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,M; cin>>N>>M;
    vector<int> P(M+1),city(M+1);
    vector<vector<int>> Ms(N+1,vector<int>());
    
    for(int i=1; i<=M; i++){
        int x,y; cin>>x>>y;
        P[i]=x;
        city[i]=y;
        Ms[x].push_back(y);
    }

    for(int i=1; i<=N; i++){
        sort(Ms[i].begin() , Ms[i].end());
    }

    for(int i=1; i<=M; i++){
        cout << setfill('0') << setw(6) << right << P[i];
        auto ite = lower_bound(Ms[P[i]].begin(), Ms[P[i]].end(), city[i]);
        cout << setfill('0') << setw(6) << right << ite - Ms[P[i]].begin() + 1;
        cout << endl;
    }

}
