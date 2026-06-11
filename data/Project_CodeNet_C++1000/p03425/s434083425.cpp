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
    string s;
    vector<pair<char,ll>> v(5);
    vector<char> c={'M','A','R','C','H'};
    REP(i,5){
        v[i].first=c[i];
    }
    REP(i,n){
        cin>>s;
        char ini=s[0];
        REP(j,5){
            if(v[j].first==ini){
                v[j].second++;
                break;
            }
        }
    }
    ll sum=0;
    REP(i,3){
        ll a=v[i].second;
        FOR(j,i+1,4){
            ll b=v[j].second;
            FOR(k,j+1,5){
                ll c=v[k].second;
                sum+=a*b*c;
            }
        }
    }
    cout<<sum;
    return 0;
}
