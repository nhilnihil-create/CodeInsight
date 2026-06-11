#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;
int main(){
    ll n;
    cin>>n;
    ld t,a;
    cin>>t>>a;
    vector<ld> h(n);
    REP(i,n)cin>>h[i];
    ld ans, m=INF;
    REP(i,n){
        ld temp=t-h[i]*0.006;
        ld dif=abs(temp-a);
        if(m>dif){
            m=dif;
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
