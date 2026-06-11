#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
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
//printf("%.10f\n", N);
/*
ll fibo(ll n){
    if(memo[n] != 0)return memo[n];
    if(n <= 1)return n;
    else return memo[n] = fibo(n - 1)+ fibo(n - 2);
}*/
/*  vector<ll> vec = {1,2,5,6,8,9,10};
    cout << binary_search(all(vec),5) << endl; -> true*/
/*
    vector<ll> vec = {1,2,5,6,8,9,10};
    auto n = upper_bound(all(vec),4);
    cout << *n << endl; -> 5*/
/*
    cout << fixed << setprecision(15);
    */
int main(){
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;//s = N,t = M
    ll num = gcd(N,M);
    ll lcm = N / num * M;
    if(num == 1){
        if(S[0] == T[0])cout << N / num * M << endl;
        else cout << -1 << endl;
    }
    else{
        bool ans = true;
        ll m = lcm / N;
        ll n = lcm / M;
        ll kai = lcm / num;
        rep(i,num){
        if(S[i * n] != T[i * m])ans = false;
        }
        if(ans)cout << lcm << endl;
        else cout << -1<< endl;
    }
}