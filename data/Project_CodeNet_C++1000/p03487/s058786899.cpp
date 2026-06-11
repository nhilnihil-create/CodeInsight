#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
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
    ll n;cin>>n;
    vector<ll> v(n),list;
    REP(i,n)cin>>v[i];
    map<ll,ll> mp;
    REP(i,n){
        ll a=v[i];
        if(mp.find(a)!=mp.end()){
            mp.at(a)++;
        }else{
            mp.insert(make_pair(a,1));
            list.push_back(a);
        }
    }
    ll sum=0;
    REP(i,SIZE(list)){
        ll key=list[i];
        ll value=mp.at(key);
        if(key>value){
            sum+=value;
        }else if(key<value){
            sum+=value-key;
        }
    }
    cout<<sum<<endl;
    return 0;
}
