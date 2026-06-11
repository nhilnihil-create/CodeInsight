#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll n;cin>>n;
    vector<pair<ll,ll>> v;
    REP(i,n){
        ll a;
        cin>>a;
        v.push_back(make_pair(a,i));
    }
    sort(ALL(v));
    vector<ll> w(n);
    REP(i,n){
        ll median,num;
        if(i<=(n/2)-1){
            median=v[n/2].first;
        }else{
            median=v[(n/2)-1].first;
        }
        num=v[i].second;
        w[num]=median;
    }
    REP(i,n){
        cout<<w[i]<<endl;
    }

    return 0;
}
