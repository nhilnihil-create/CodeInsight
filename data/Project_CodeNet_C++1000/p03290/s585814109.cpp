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
#define RREP(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;
int main(){
    ll d,g; cin>>d>>g;
    vector<pair<ll,ll>> v(d);
    REP(i,d){
        cin>>v[i].first>>v[i].second;
    }
    ll ans=INF;
    REP(bit,1<<d){
        ll point=0;
        ll big=-1;
        ll prbnumsum=0;
        REP(i,d){
            if(bit & 1<<i){
                ll prbnum=v[i].first, cmp=v[i].second;
                point+=100*(i+1)*prbnum+cmp;
                prbnumsum+=prbnum;
            }else{
                if(big<i)big=i;
            }
        }
        if(g<=point && ans>prbnumsum)ans=prbnumsum;
        else if(g>point){
            REP(i,v[big].first){
                point+=100*(big+1);
                prbnumsum++;
                if(g<=point && ans>prbnumsum)ans=prbnumsum;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
