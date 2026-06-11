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
    int n;
    cin >> n;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    if(a[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    ll answer = 0;
    FORR(i,n-1,1){
        if(a[i]-a[i-1]==1)answer++;
        else if(a[i] - a[i-1] > 1){
            cout << -1 << endl;
            return 0;
        }
        else answer+=a[i];
    }
    cout << answer << endl;
    return 0;
}