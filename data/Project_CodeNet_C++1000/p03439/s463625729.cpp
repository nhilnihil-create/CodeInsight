#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<bool> seat(20);
    string fir, las;
    cout << 0 << endl;
    cin >> fir;
    if(fir == "Vacant") return 0;
    cout << n-1 << endl;
    cin >> las;
    if(las == "Vacant") return 0;
    int l = 0, r = n - 1;
    rep(i,18){
        int mid = (l + r) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if(s == "Vacant") return 0;
        if((s == las) ^ ((r - mid)%2 == 0)){
            l = mid;
            fir = s;
        }
        else{
            r = mid;
            las = s;
        }
    }
    return 0;
}
