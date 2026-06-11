
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

ll gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,b%a);
    }
}


int main(){
    ll n, x;
    cin >> n >> x;
    ll ans=0;
    ll temp=0;
    //一旦最初の入力とスタートの距離をansにし、入力ごとに最大公約数に更新していく
    cin >> temp;
    ans = abs(temp-x);

    for(int i=1; i<n; i++){
        cin >> temp;
        ans = gcd(ans,abs(temp-x));
    }
    cout << ans << endl;




}