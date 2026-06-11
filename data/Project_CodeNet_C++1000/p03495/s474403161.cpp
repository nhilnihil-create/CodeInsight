#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
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
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    REP(i,n){
        cin>>v[i];
    }
    vector<ll> list;
    map<ll,ll>  w;
    REP(i,n){
        ll cnt=w.count(v[i]);
        if(cnt){
            w.at(v[i])++;
        }else{
            w.insert(make_pair(v[i],1));
            list.push_back(v[i]);
        }
    }
    ll s=SIZE(list);
    vector<ll> x(s);
    REP(i,s){
        x[i]=w.at(list[i]);
    }
    sort(ALL(x));
    ll sum=0;
    REP(i,s-k){
        sum+=x[i];
    }
    cout<<sum;
    return 0;
}
