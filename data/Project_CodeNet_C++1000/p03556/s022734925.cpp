#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int64_t N;
    cin >> N;
    int64_t x = 1;
    while(true){
        if(pow(x + 1, 2) > N){
            break;
        }
        else{
            x++;
        }
    }
    int ans = pow(x, 2);
    cout << ans << endl;
}
