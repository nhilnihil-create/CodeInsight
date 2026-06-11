#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> a_l(N,0);
    vector<int> a_r(N,0);

    rep(i,1,N) {
        if (S[i-1]=='W') {
            a_l[i] = a_l[i-1]+1;
        }
        else {
             a_l[i] = a_l[i-1];
        }
    }

    for (int i=N-2; i>=0;i--) {
        if (S[i+1]=='E') {
            a_r[i] = a_r[i+1]+1;
        }
        else {
             a_r[i] = a_r[i+1];
        }
    }

    int ans = INF;

    rep(i,0,N) {
        ans = min(ans,a_l[i]+a_r[i]);

    }

    cout << ans << endl;

 }

