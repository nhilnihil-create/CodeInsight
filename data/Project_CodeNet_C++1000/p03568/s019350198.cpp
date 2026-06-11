#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,n) for(int i=0 ; i < (int) (n) ; ++i )

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int odd = 0;
    rep(i,n)
    {
        int k;
        cin >> k;
        odd += k%2;
    }

    cout << (int)(pow(3,n) - pow(2,n-odd)) << endl;
}


