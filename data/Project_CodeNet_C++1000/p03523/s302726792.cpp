#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    string S, ct = "AKIHABARA", cr = "";
    cin >> S;

    int cts = 0;
    rep(i, 9) {
        //cout << i << " " << ct[i] << " " << cts << " " << S[cts] << endl;
        if (cts >= (int)S.size()) {
            cr += 'A';
        }
        else if (ct[i] != S[cts]) {
            cr += 'A';
        }
        else {
            cr += S[cts];
            cts++;
        }
    }
    if ((int)S.size() >= 10) cr = "";

    //cout << cr << endl;

    cout << (ct == cr ? "YES" : "NO") << endl;
    return 0;
}