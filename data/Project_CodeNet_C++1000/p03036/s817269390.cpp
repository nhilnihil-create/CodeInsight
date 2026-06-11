
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;

const int MAX=1e6;
vector<pll>g[MAX];
bool vis[MAX];
int ans[MAX];
void dfs(pll u){
    vis[u.ft]=true;
    for(auto &x:g[u.ft]){
        if(!vis[x.ft]){
            if(x.sd%2==0){
                ans[x.ft]=ans[u.ft];
            }else{
                ans[x.ft]=!ans[u.ft];
            }
          dfs(x);
        }
    }
}
int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif
int r,d,x;
cin>>r>>d>>x;
forn(i,0,10){
    x=x*r-d;
    cout<<x<<endl;
}
}
