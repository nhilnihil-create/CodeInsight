#include<bits/stdc++.h>
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

#define int long long
#define cint cpp_int
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) (((a)+(b)-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2
#define PI acos(-1.0)
#define leng(n) (int)(log10(n)+1)


typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vvout(VVi &v){for(int i=0;i<(v).size();i++) vout(v[i]);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int digit(int k,int i){string s = to_string(k);return s[s.size()-i]-'0';}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
Vi accum(Vi v){Vi ret((v).size());ret[0]=v[0];REP(i,1,(v).size()) ret[i]=ret[i-1]+v[i];return ret;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

Vi yakusuu(int n){
    Vi ret;
    for(int i=1 ; i*i<=n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n/i);
        }
    }
    sort(ALL(ret));
    return ret;
}

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
    int n;
    cin>>n;
    Vs s(n);
    REP(i,0,n){
        cin>>s[i];
    }

    int ans=0;
    REP(i,0,n){
        Vs ss(n);
        REP(j,0,n){
            ss[j]=s[(j+i)%n];
        }
        // REP(j,0,n) cout<<ss[j]<<endl;
        // cout<<endl;
        bool check=false;
        REP(j,0,n){
            REP(k,0,n){
                if(ss[j][k]!=ss[k][j]){
                    check=true;
                    break;
                }
            }
            if(check) break;
        }
        if(check==false) ans += n;
    }
    cout<<ans<<endl;
    return 0;
}
