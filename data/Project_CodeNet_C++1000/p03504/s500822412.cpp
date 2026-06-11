#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int n, c;
    cin >> n >> c;
    int S[1000000];
    fill(S, S + 1000000, 0);
    //チャンネル別で考える
    int Sc[30][100100];
    rep(i, 30) fill(Sc[i], Sc[i] + 100100, 0);
    rep(i, n){
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        Sc[c][s]++;
        Sc[c][t]--;
    }

    rep(i, 100100){
        rep(j, 30){
            if(Sc[j][i] == 1){
                S[2*i - 1]++;
            }else if(Sc[j][i] == -1){
                S[2*i]--;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < 1000000; i++){
        S[i] += S[i-1];
        ans = max(S[i], ans);
    }
    cout << ans << endl;
}