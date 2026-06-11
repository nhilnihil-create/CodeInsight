#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int a;
    int cnt[4] = {};
    REP(i,6){
        cin >> a;
        a--;
        cnt[a]++;
    }
    REP(i,4){
        if(!(cnt[i] == 1 || cnt[i] == 2)){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}