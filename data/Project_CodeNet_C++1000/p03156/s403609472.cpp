#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n,a,b;
    cin >> n >> a >> b;
    int p[n];
    REP(i,n){
        cin >> p[i];
    }
    int cnt_a = 0, cnt_b = 0, cnt_c = 0;
    REP(i,n){
        if(p[i] <= a){
            cnt_a++;
        }else if(p[i] <= b){
            cnt_b++;
        }else{
            cnt_c++;
        }
    }
    cout << min(cnt_a, min(cnt_b, cnt_c)) << endl;
}