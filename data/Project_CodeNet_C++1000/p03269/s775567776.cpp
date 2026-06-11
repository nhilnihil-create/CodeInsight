#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;

int main(){
    int l; cin>>l;
    int b[20]={};
    FOR(i,0,20){
        b[i]=(l>>i)&1;
    }
    int v;
    vector<int> edge[3];
    bool flag=true;
    int nowl=0;
    ROF(i,0,20){
        if(b[i]){
            if(flag){
                v=i;
                FOR(j,0,i){
                    edge[0].PB(j);
                    edge[1].PB(j+1);
                    edge[2].PB(0);
                    edge[0].PB(j);
                    edge[1].PB(j+1);
                    edge[2].PB(1<<j);
                }
                flag=false;
            }else{
                edge[0].PB(i);
                edge[1].PB(v);
                edge[2].PB(nowl);
            }
            nowl+=(1<<i);
        }
    }
    cout<<v+1<<" "<<edge[0].size()<<endl;
    FOR(i,0,edge[0].size()){
        printf("%d %d %d\n",edge[0][i]+1,edge[1][i]+1,edge[2][i]);
    }
}
