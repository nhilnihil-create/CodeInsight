#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    int cnt = 0;
    vector<int> A(N);
    rep(i, N-1){
        if(S.at(i)=='A'&&S.at(i+1)=='C'){
            cnt++;
        }
        A.at(i) = cnt;
    }
    A.at(N-1) = cnt;

    rep(i, Q){
        int l, r; cin >> l >> r;
        int ans = A.at(r-1)-A.at(l-1);
        if(S.at(l-1)=='A'&&S.at(l)=='C') ans++;
        if(S.at(r-1)=='A'&&A.at(r-1)-A.at(r-2)==1) ans--;
        cout << ans << endl;
    }
}