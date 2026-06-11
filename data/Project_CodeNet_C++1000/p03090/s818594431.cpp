#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n; cin >> n;
    if(n % 2 == 0){
        int num = ((n-2)*n)/2;
        cout << num << endl;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(i + j + 2 != n+1) cout << i+1 << ' ' << j+1 << endl;
            }
        }
    }else{
        int num = ((n-1)*(n-1))/2;
        cout << num << endl;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(i + j + 2!= n) cout << i+1 << ' ' << j+1 << endl;
            }
        }
    }
}