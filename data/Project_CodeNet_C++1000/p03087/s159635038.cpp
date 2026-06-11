#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> A;
    A.push_back(0);

    char now = 'X';
    int num = 0;
    rep(i,N) {
        if (now=='A' && S[i]=='C') {
            num++;
            A.push_back(num);
            now = 'C';
        }
        else {
            now = S[i];
            A.push_back(num);
        }
    }

    rep(i,Q) {
        int l,r;
        cin >> l >> r;
        int ans = A[r]-A[l];
        cout << ans << endl;
    }
}