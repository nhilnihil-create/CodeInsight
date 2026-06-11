
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    else{
        gcd(b,a%b);
    }
}

//最大公約数の問題に帰着できる
int main(){
    ll n;
    cin >> n;
    int ans=0;
    cin >> ans;
    for(int i=0; i<n-1; i++){
        int temp;
        cin >> temp;
        ans = gcd(ans,temp);
    }
    cout << ans << endl;
}