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
    
    
    ini(x);
    ini(x1);
    ini(x_);
    ini(pizza1);
    ini(pizza2);
    int tmp1 = x*pizza1+x1*pizza2;
    int tmp2 = x_*2*pizza1+(pizza1<pizza2?(pizza2-pizza1)*x1:0);
    int tmp3 = x_*2*pizza2+(pizza2<pizza1?(pizza1-pizza2)*x:0);
    int tmp = min({tmp1,tmp2,tmp3});
    out(tmp);
    


  
    
    
    
    
    
    
    
    return 0;
}
