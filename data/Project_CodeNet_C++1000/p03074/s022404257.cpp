#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    ll n,k;
    string s;
    cin >> n >> k >> s;
    vector<ll> p;
    ll c1=0,c2=0;
    for (ll i=0;i<n;i++){
        if (s[i]=='0'){
            if (c1==0){
                c2++;
                continue;
            }
            p.push_back(c1);
            c2++;
            c1=0;
        }else{
            if (c2==0){
                c1++;
                continue;
            }
            p.push_back(c2);
            c2=0;
            c1++;
        }
    } 
    if (c1)p.push_back(c1);
    if (c2)p.push_back(c2);
    ll ans=0,c=0,count=0;
    if (s[0]=='0'){
        for (ll i=0;i<p.size();i++){
            if (i%2==0){
                c++;
            }
            count+=p[i];
            if (c>k){
                count-=p[i-(k*2)];
                if (i-(k*2)-1>=0)count-=p[i-(k*2)-1];
                c--;
            }
            ans=max(count,ans);
        }
    }else{
        for (ll i=0;i<p.size();i++){
            if (i%2){
                c++;
            }
            count+=p[i];
            if (c>k){
                count-=p[i-(k*2)];
                if (i-(k*2)-1>=0)count-=p[i-(k*2)-1];
                c--;
            }
            ans=max(count,ans);
        }
    }
    cout << ans << endl;
    return 0;
}
