#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n,k;
    cin >> n >> k;
    if(k <= (n + 1) / 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}