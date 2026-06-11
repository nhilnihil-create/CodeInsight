#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n,m;
    cin >> n >> m;
    
    vector<ll>x(m);
    REP(i,m)cin >> x[i];
    if(n >= m){
        cout << 0 << endl;
        return 0;
    }
    vector<ll>diff(m-1);
    SORT(x);
    ll all = x[m-1]-x[0];
    REP(i,m-1)diff[i]=x[i+1]-x[i];
    SORT(diff);
    reverse(ALL(diff));
    REP(i,n-1){
        all-=diff[i];
    }
    cout << all << endl;
    return 0;
}