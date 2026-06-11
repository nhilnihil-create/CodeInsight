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
ll f(ll x){
    ll count = 0;
    ll answer = 0;
    REP(i,40){
        ll index = (1ll << i);
        count += ((x+1)/(index*2))*index;
        count += max(0ll,(x+1)%(index*2)-index);
        if(count%2)answer+=index;
        count = 0;
    }
    return answer;
}
int main(){
    ll a,b;
    cin >> a >> b;
    cerr << f(a) << " " << f(b) << endl;
    cout << (f(max(a-1,0ll))^f(b)) << endl;
    return 0;
}