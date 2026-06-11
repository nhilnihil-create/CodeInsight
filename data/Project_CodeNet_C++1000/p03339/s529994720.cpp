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
    string s;cin>>s;
    vector<ll> w(n),e(n);
    ll w_count=0,e_count=0;
    REP(i,n){
        s[i]=='W'?w_count++:e_count++;
        w[i]=w_count;
        e[i]=e_count;
    }
    ll min=n;
    REP(i,n){
        ll left = (i==0)? 0 :w[i-1];
        ll right= e[n-1]-e[i];
        ll sum=left+right;
        if(min>sum){
            min=sum;
        }
    }
    cout<<min;
    return 0;
}
