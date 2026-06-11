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
    ll n;
    cin >> n;
    ll v1[n/2],v2[n/2];
    for (ll i=0;i<n;i++){
        if (i%2)cin >> v2[i/2];
        else cin >> v1[i/2];
    }
    sort(v1,v1+(n/2));
    sort(v2,v2+(n/2));
    vector<pair<ll,ll> > vec1,vec2;
    ll c=1;
    for (ll i=1;i<n/2;i++){
        if (v1[i-1]!=v1[i]){
            pair<ll,ll> p;
            p=make_pair(c,v1[i-1]);
            c=1;
            vec1.push_back(p);
        }else{
            c++;
        }
    }
    pair<ll,ll> p;
    p=make_pair(c,v1[(n/2)-1]);
    c=1;
    vec1.push_back(p);
    for (ll i=1;i<n/2;i++){
        if (v2[i-1]!=v2[i]){
            pair<ll,ll> p;
            p=make_pair(c,v2[i-1]);
            c=1;
            vec2.push_back(p);
        }else{
            c++;
        }
    }
    p=make_pair(c,v2[(n/2)-1]);
    c=1;
    vec2.push_back(p);
    sort(ALL(vec1),pairCompare);
    sort(ALL(vec2),pairCompare);
    ll ans=0;
    if (vec1.size()==1){
        if (vec2.size()==1){
            if (vec2[0].second==vec1[0].second){
                ans=vec2[0].first;
            }
            cout << ans << endl;
            return 0;
        }
        if (vec2[vec2.size()-1].second==vec1[vec1.size()-1].second){
            ans=(n/2)-vec2[vec2.size()-2].first;
        }
        ans=(n/2)-vec2[vec2.size()-1].first;
        cout << ans << endl;
    }else{
        if (vec2.size()==1){
            if (vec2[vec2.size()-1].second==vec1[vec1.size()-1].second){
                ans=(n/2)-vec1[vec1.size()-2].first;
                cout << ans << endl;
                return 0;
            }
            ans=(n/2)-vec1[vec1.size()-1].first;
            cout << ans << endl;
            return 0;
        }
        if (vec2[vec2.size()-1].second==vec1[vec1.size()-1].second){
            ll ans2=0;
            ans+=(n/2)-vec2[vec2.size()-1].first;
            ans+=(n/2)-vec1[vec1.size()-2].first;
            ans2+=(n/2)-vec2[vec2.size()-2].first;
            ans2+=(n/2)-vec1[vec1.size()-1].first;
            cout << min(ans2,ans) << endl;
            return 0;
        }
        ans+=(n/2)-vec2[vec2.size()-1].first;
        ans+=(n/2)-vec1[vec1.size()-1].first;
        cout << ans << endl;
    }
    return 0;
}
