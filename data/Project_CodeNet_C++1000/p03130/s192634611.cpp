#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    //ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    vector<ll> a={0,0,0,0};
    for(int i=0;i<6;i++){
        int x;
        cin >> x;
        a[x-1]++;
    }
    sort(a.begin(), a.end());
    if(a[0]==1 && a[1]==1 && a[2]==2)cout << "YES";
    else cout << "NO" << endl;
    


}

/*



 */
