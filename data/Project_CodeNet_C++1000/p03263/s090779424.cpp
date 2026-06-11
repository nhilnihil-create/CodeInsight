#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(int i=0;i<n;i++)
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

struct state{
    int a,b,c,d;
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w){
        cin>>a[i][j];
    }
    vector<state> ans;
    rep(i,h){
        if(i%2==0){
            rep(j,w-1){
                if(a[i][j]%2){
                    a[i][j]--;
                    a[i][j+1]++;
                    ans.push_back({i+1,j+1,i+1,j+2});
                }
            }
            if(a[i][w-1]%2 && i!=h-1){
                a[i][w-1]--;
                a[i+1][w-1]++;
                ans.push_back({i+1,w,i+2,w});
            }
        }else{
            for(int j=w-1;j>=1;j--){
                if(a[i][j]%2){
                    a[i][j]--;
                    a[i][j-1]++;
                    ans.push_back({i+1,j+1,i+1,j});
                }
            }
            if(a[i][0]%2 && i!=h-1){
                a[i][0]--;
                a[i+1][0]++;
                ans.push_back({i+1,1,i+2,1});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x.a<<' '<<x.b<<' '<<x.c<<' '<<x.d<<endl;
    }
}