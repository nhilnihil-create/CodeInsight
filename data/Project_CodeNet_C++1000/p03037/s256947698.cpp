
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

int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif
int n,m;
cin>>n>>m;
vector<pii> v;
forn(i,0,m){
    int x,y;
    cin>>x>>y;
    v.pb({x,y});
}
int L=-1,M=n;
for(auto &x:v){
    L=max(L,x.ft);
    M=min(M,x.sd);
}
    int ans=(M-L)+1;
    //cout<<max((M-L)+1,1)<<endl;
    if(ans<0) ans=0;
    cout<<ans<<endl;
    

}
