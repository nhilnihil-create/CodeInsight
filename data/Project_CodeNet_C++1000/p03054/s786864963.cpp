#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int cha(char a){
    if(a == 'L') return 0;
    elif(a == 'U') return 1;
    elif(a == 'R') return 2;
    else return 3;
}

int main(){
    int H, W, N, x, y;
    cin >> H >> W >> N >> x >> y;
    string S, T;
    cin >> S >> T;
    int wide[4];
    fill_n(wide, 4, 0);
    rep3(i, N){
        int j = cha(T[i]);
        j += 2;
        j %= 4;
        if(wide[j] > 0) wide[j]--;
        int k = cha(S[i]);
        wide[k]++;
        if(wide[0] + wide[2] >= W || wide[1] + wide[3] >= H){
            cout << "NO" << endl;
            exit(0);
        }
    }
    if(y>wide[0] && x>wide[1] && y<=W-wide[2] && x<=H-wide[3]) cout << "YES" << endl;
    else cout << "NO" << endl;
}