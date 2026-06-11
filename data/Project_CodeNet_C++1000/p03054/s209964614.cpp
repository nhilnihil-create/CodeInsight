#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int H,W,N;
    int sr,sc;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    sr--,sc--;
    string S,T;
    cin >> S >> T;

    string ans = "YES";
    // LR
    int wmax,wmin;
    wmax = W-1;
    wmin = 0;
    if (S[N-1]=='L') wmin++;
    else if (S[N-1]=='R') wmax--;

    //cout << wmin << " " << wmax << endl;

    for (int i=N-2; i>=0; i--) {
        if (T[i]=='L') wmax = min(wmax+1, W-1);
        else if (T[i]=='R') wmin = max(wmin-1, 0);

        if (S[i]=='L') wmin++;
        else if (S[i]=='R') wmax--;

        if (wmax<wmin) ans = "NO";
        //cout << wmin << " " << wmax << endl;
    }
    if (wmin>sc || wmax<sc) ans = "NO";

    //cout << ans << endl;

    // UD
    int hmax,hmin;
    hmax = H-1;
    hmin = 0;
    if (S[N-1]=='U') hmin++;
    else if (S[N-1]=='D') hmax--;

    //cout << hmin << " " << hmax << endl;

    for (int i=N-2; i>=0; i--) {
        if (T[i]=='U') hmax = min(hmax+1, H-1);
        else if (T[i]=='D') hmin = max(hmin-1, 0);

        if (S[i]=='U') hmin++;
        else if (S[i]=='D') hmax--;

        if (hmax<hmin) ans = "NO";
        //cout << S[i] << " " << T[i] << " " << hmin << " " << hmax << endl;
    }
    if (hmin>sr || hmax<sr) ans = "NO";
    cout << ans << endl;

}
