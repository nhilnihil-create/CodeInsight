#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    string a,b,c;
    cin >> a >> b >> c;
    ll sum=0;
    for(int i=0;i<N;i++){
        if(a[i]!=b[i])sum++;
        if(a[i]!=c[i] && b[i]!=c[i])sum++;
    }
    cout << sum << endl;
    


}

/*



 */

