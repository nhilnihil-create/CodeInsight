#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    int x;  cin >> x;
    int ans = 1;
    for(int i=1; i<1001; i++){
        for(int j=2; j<15; j++){
            int tmp = pow(i,j);
            if(tmp > x)    break;
            if(tmp <= x)   ans = max(ans,tmp);
        }
    }
    print(ans);
}