#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d; cin>>d;
    string ans = "";
    switch (d)
    {
    case 25:
ans = "Christmas";
        /* code */
        break;
    case 24:
        /* code */
ans = "Christmas Eve";
        break;
    case 23:
        /* code */
ans = "Christmas Eve Eve";
        break;
    case 22:
        /* code */
ans = "Christmas Eve Eve Eve ";
        break;
    default:
        break;
    }
    cout << ans <<endl;

}