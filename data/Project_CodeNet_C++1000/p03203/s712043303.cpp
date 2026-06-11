#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll h,w,n,ans=INF,s,a;
vector<ll>p[200005];
set<ll>q[200005];
int main(void){
    cin>>w>>h>>n;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        p[y].PB(x);
        q[y].insert(x);
    }
    for(int i=0;i<h;i++){
        p[i].PB(w);
        q[i].insert(w);
        sort(p[i].begin(),p[i].end());
    }
    bool o=true;
    for(int i=0;i<h&&o;i++){
        for(int j=0;j<p[i].size();j++){
            if(a+1==p[i][j]){
                ans=min(ans,s+1);
                s++;
                o=false;
                break;
            }
            if(a+1<p[i][j]){
                ans=min(ans,p[i][j]-a+s);
                a++;
                s++;
                if(i+1<h){
                    while(q[i+1].find(a)!=q[i+1].end()&&a<p[i][j]){
                        a++;
                        s++;
                        if(a==p[i][j])o=false;
                    }
                }
                break;
            }
        }
    }
    cout<<ans<<endl;
}
