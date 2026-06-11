#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;
using ipair= pair<int,int>;
bool operator>(const ipair a,const ipair b){return a.first > b.first;};

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> P(M),Y(M);
    vector<priority_queue<ipair,vector<ipair>,greater<ipair>>> V(N);
    rep(i,M){
        cin >> P[i] >> Y[i];
        V[P[i]-1].push({Y[i],i});
    }

    ipair p;
    vector<ipair> ans(M);
    int x;
    rep(i,N){
        x=0;
        while(!V[i].empty()){
            x++;
            p = V[i].top();
            ans[p.second].first=(i+1);
            ans[p.second].second=x;
            V[i].pop();
        }
    }

    rep(i,M){
        printf("%06d%06d\n",ans[i].first,ans[i].second);
    }

    


}
