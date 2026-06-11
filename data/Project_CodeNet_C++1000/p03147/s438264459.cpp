#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double EPS=1e-10;
const double PI=acos(-1);

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> h(n),a(n,0);
    rep(i,n){
        cin>>h[i];
    }
    int ans=0;
    while(true){
        int ma=0,l=-1,r;
        rep(i,n)FOR(j,i,n){
            bool flag=true;
            FOR(k,i,j+1){
                if(a[k]>=h[k]){
                    flag=false;
                }
            }
            if(flag){
                if(chmax(ma,int(j-i+1))){
                    l=i,r=j;
                }
            }
        }
        if(l==-1){
            break;
        }
        while(true){
            bool flag=false;
            FOR(i,l,r+1){
                a[i]++;
                if(a[i]==h[i]){
                    flag=true;
                }
            }
            ans++;
            if(flag) break;
        }
        bool flag=true;
        rep(i,n){
            if(a[i]!=h[i]) flag=false;
        }
        if(flag) break;
    }
    cout<<ans<<endl;
}