#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,ll> l_l;
const ll INF = 10000000100;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<l_l> G[N+1];
    for(int i=0; i<M; i++){
        int a,b,c; cin >> a >> b >> c;
        G[a].push_back(l_l(b,c));
        G[b].push_back(l_l(a,-c));
    }
    vector<ll> x(N+1,INF);
    for(int i=1; i<=N; i++){
        if(x[i]==INF){
            x[i]=0;
            queue<l_l> q;
            q.push(l_l(x[i],i));
            while(!q.empty()){
                l_l now=q.front();q.pop();
                ll nowpos=now.second;
                ll nowdist=now.first;
                for(auto Next: G[nowpos]){
                    ll newpos=Next.first;
                    if(x[newpos]==INF){
                        x[newpos]=nowdist+Next.second;
                        q.push(l_l(x[newpos],newpos));
                    }
                    else{
                        if(x[newpos]!=nowdist+Next.second){
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}