#include <iostream>
#include <map>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    map<ll, ll> m;
    for(int i=1; i<=N; i++){
        int d = i % K;
        if(m.count(d) == 0) m[d] = 1;
        else m[d]++;
    }

    ll ans;
    ans = m[0]*m[0]*m[0];
    if(K %2 == 0){
        ans += m[K/2]*m[K/2]*m[K/2];
    }

    cout << ans << endl;

    return 0;
}
