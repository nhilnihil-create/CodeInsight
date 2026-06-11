#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    int n;cin>>n;
    vi v(n);
    rep(i,n){
        cin>>v[i];
    }
    vi p(100005,0),e(100005,0);
    rep(i,n){
        if(i%2==0)p[v[i]]++;
        else e[v[i]]++;
    }
    int pf = max_element(been(p))-p.begin();
    int ef = max_element(been(e))-e.begin();
    if(pf==ef){
        int pc =p[pf],ec=e[ef];
        p.erase(p.begin()+pf);e.erase(e.begin()+ef);
        pf = max_element(been(p))-p.begin();
        ef = max_element(been(e))-e.begin();
        cout<<min(n-pc-e[ef],n-ec-p[pf])<<endl;
    }
    else {
        cout<<n-p[pf]-e[ef]<<endl;
    }
}