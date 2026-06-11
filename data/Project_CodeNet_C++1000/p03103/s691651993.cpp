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
    ll n,m,a,b;
    cin>>n>>m;
    vector<pair<ll,ll>> v(n);
    REP(i,n){
        cin>>a>>b;
        v[i]=make_pair(a,b);
    }
    sort(ALL(v));
    ll bottles=0, cost=0, i=0;
    while(bottles<m){
        bottles+=v[i].second;
        cost+=v[i].first*v[i].second;
        if(bottles>=m){
            break;
        }
        i++;
    }
    while(bottles>m){
        bottles--;
        cost-=v[i].first;
    }
    cout<<cost;
}
