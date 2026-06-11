#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;

const double PI=acos(-1);


int main(){
    ll K,A,B;
    cin >> K >> A >> B;

    ll ans = max(K+1, (K-(A-1))%2+((K-(A-1))/2-1)*(B-A)+B);
    cout << ans << endl;

}
