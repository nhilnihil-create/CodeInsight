#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e9 
typedef long long ll;
typedef long double ld;
int main(){
    ll n, m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    REP(i,m){
        int a,b;
        cin>>a>>b;
        v[i].first=b, v[i].second=a;
    }
    sort(ALL(v));
    vector<bool> bridge(n);
    int brk=-1;
    REP(i,m){
        int from=v[i].second, to=v[i].first;
        if(from<=brk&&brk<to){
            continue;
        }else{
            bridge[to-1]=true;
            brk=to-1;
        }
    }
    int ans=0;
    REP(i,n)if(bridge[i])ans++;
    cout<<ans<<endl;
    return 0;
}
