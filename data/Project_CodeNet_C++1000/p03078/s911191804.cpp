#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100000
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int main(){
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<ll>a(x);
    vector<ll>b(y);
    vector<ll>c(z);
    REP(i,x)IN(a[i]);
    REP(i,y)IN(b[i]);
    REP(i,z)IN(c[i]);
    vector<ll>w(x*y);
    REP(i,x){
        REP(j,y){
            w[j+y*i]=a[i]+b[j];
        }
    }
    sort(ALL(w));
    reverse(ALL(w));
    int t=z*min(x*y,3000);
    vector<ll>r(t);
    REP(i,min(x*y,3000)){
        REP(j,z){
            r[j+z*i]=c[j]+w[i];
        }
    }
    sort(ALL(r));
    reverse(ALL(r));
    REP(i,k)OUT(r[i]);
    return 0;
}