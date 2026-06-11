#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 9223372036854775806ll;
const ll MOD = 1000000007LL;
/*メモ 
*/
int main(){
    string s;
    std::cin >> s;
    int n=s.size();
    std::vector<bool> a(26,0);
    rep(i,n){
        a[s[i]-'a']=1;
    }
    if(s.size()!=26){
        char c;
        rep(i,26)if(!a[i]){
            c=+'a'+i;
            break;
        }
        std::cout << s+c << std::endl;
        exit(0);
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba")std::cout << -1 << std::endl;
        else {
            string ss=s;
            next_permutation(all(s));
            rep(i,n){
                if(ss[i]!=s[i]){
                    std::cout << s.substr(0,i+1) << std::endl;
                    exit(0);
                }
            }
            //std::cout << s << std::endl;
        }
    }
}