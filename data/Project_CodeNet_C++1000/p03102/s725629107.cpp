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
    int n,m,c;
    cin >>n >> m >> c;
    vector<int>b(m);
    REP(i,m)cin >> b[i];
    int a[n][m];
    REP(i,n)REP(j,m)cin >> a[i][j];
    ll answer = 0;
    REP(i,n){
        ll count = 0;
        REP(j,m){
            count+=a[i][j]*b[j];
        }
        if(count+c>0)answer++;
    }
    cout << answer << endl;
    return 0;
}