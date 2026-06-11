#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n, k; cin >> n >> k;
    if(k %2 == 1){
        ll ans = n/k;

        cout << ans * ans * ans << endl;
        return 0;
    }

    ll jud = n/k;
    ll jud2 = n/(k/2) - jud;

    cout << jud * jud * jud + jud2 * jud2 * jud2 << endl;

}
