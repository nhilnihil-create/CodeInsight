#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
#define INF -99999999 
using namespace std;
 
int main(){
    int N,M; cin >> N >> M;
    ll ans = 100*(N-M)+1900*M;
    for (int i = 0; i < M; i++)
    {
        ans *= 2;
    }
    cout << ans << endl;
}