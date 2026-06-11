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
    ll k,a,b;
    cin >> k >> a >> b;
    if(b-a < 3){
        cout << k + 1 << endl;
        return 0;
    }
    if(k <= a){
        cout << k + 1 << endl;
        return 0;
    }
    k -= (a-1);
    ll answer = a;
    answer += (k/2)*(b-a);
    if(k%2)answer++;
    cout << answer << endl;
    return 0;
}