#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n,h,w;
    cin >> n >> h >> w;
    vector<ll>a(n),b(n);
    ll answer = 0;
    REP(i,n){
        cin >> a[i] >> b[i];
        if(a[i] >= h && b[i] >= w)answer++;
    }

    cout << answer << endl;

    return 0;
}