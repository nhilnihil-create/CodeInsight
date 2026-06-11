#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n[4];
    REP(i,4){
        cin >> n[i];
    }
    sort(n, n + 4);
    if(n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}