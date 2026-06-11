#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int cnt[2][202020];

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[n];
    rep(i,n)a[i]=(s[i]=='A');
    vector<int> v[n];
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
        cnt[a[x]][y]++;
        cnt[a[y]][x]++;
    }
    bool ok[n];
    queue<int> q;
    rep(i,n){
        ok[i]=(cnt[1][i]>0&&cnt[0][i]>0);
        if(!ok[i])q.push(i);
    }
    while(q.size()){
        int x=q.front();q.pop();
        for(auto& u:v[x]){
            if(!ok[u])continue;
            if(--cnt[a[x]][u]==0){
                ok[u]=false;
                q.push(u);
            }
        }
    }
    rep(i,n){
        if(ok[i]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}