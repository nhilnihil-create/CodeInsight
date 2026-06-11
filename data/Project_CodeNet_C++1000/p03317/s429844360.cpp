
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, k;
    cin >> n >> k;


    int ans = (n-1)/(k-1);
    if((n-1)%(k-1)!=0) ans ++;
    cout << ans << endl;
}