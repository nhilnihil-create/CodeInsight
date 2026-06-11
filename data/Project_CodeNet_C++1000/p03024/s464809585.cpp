#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    //ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    string S; cin >> S;
    //ll H,W; cin >> H >> W;
    ll sum=0;
    for(int i=0;i<S.length();i++){
        if(S[i]=='o')sum++;
    }
    if(15+sum-S.length()>=8)cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*



 */
