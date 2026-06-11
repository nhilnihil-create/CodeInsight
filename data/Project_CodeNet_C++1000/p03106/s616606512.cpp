#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    ll a, b, k;cin >> a >> b >> k;
    ll m = max(a, b);
    vec A(1000,-1);
    for(int i = 1;i <= m;i++){
        if(a % i == 0 && b % i == 0){
            A[i] = i;
        }
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    cout << A[k-1] << endl;
}