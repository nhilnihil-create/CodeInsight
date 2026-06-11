#include <bits/stdc++.h>

using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;


int32_t main() {
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    
    
    ini(n);
    ini(n1);
    int x[430000];
    int v[430000];
    x[0] = 0;
    v[0] = 0;
    x[n+1] = n1;
    v[n+1] = 0;
    FOR(i,1,n+1){in(x[i]);in(v[i]);}
    int tmpll [430000];
    int tmprr [430000];
    tmpll[0] = 0;
    tmprr[0] = 0;
    tmprr[n+1] = 0;
    FOR(i,1,n+1)tmpll[i] = tmpll[i-1]+v[i]-(x[i]-x[i-1]);
    FOR(i,1,n+1)tmpll[i] = max(tmpll[i-1],tmpll[i]);
    for(int i = n;i>=1;i--)tmprr[i] = tmprr[i+1]+v[i]-(x[i+1]-x[i]);
    for(int i = n;i>=1;i--)tmprr[i] = max(tmprr[i+1],tmprr[i]);
    
    int tmp = 0;
    FOR(i,1,n+1){
        tmp = max(tmp,tmpll[i]);
        tmp = max(tmp,tmpll[i]-x[i]+tmprr[i+1]);
        tmp = max(tmp,tmprr[i]);
        tmp = max(tmp,tmprr[i]-(n1-x[i])+tmpll[i-1]);
    }
    
    out(tmp);
  
    
    
    
    
    
    
    
    return 0;
}
