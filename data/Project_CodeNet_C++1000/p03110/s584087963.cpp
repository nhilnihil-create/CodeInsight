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
    ll N;
    cin >> N;
    string S,T;
    double ans = 0;
    rep(i,N){
        cin >> S >> T;
        if(T == "JPY"){
            ll num = stoll(S);
            ans += num;
        }
        else{
            ld num = stold(S);
            ans += num * 380000;
        }
    }
    printf("%.10f\n", ans);
}