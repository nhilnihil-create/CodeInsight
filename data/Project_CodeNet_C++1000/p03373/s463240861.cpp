#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1001001001;
const ll mod = 1000000007;
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}

int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans1,ans2,ans3;
    ans1 = A * X + B * Y;
    if(X > Y){
        ans2 = C * Y * 2 + A * (X - Y);
    }
    else{
        ans2 = C * X * 2 + B * (Y - X);
    }
    ans3 = C * max(X,Y) * 2;
    cout << min(min(ans1,ans2),ans3) << endl;
}