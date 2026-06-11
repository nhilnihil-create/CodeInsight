#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    //ll N; cin >> N;
    ll A,B; cin >> A >> B;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        if(i%2==0){
          A=A/2;
          B+=A;
        }
        else{
          B=B/2;
          A+=B;
        }
    }
    


    cout << A << ' ' << B << endl;
}

/*



 */

