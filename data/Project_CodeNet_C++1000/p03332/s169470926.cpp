//#i#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <time.h>
#include <cassert>
#include <fstream>
#include <stdio.h>
#include<unordered_map>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
template<typename T>
void vdeb(std::vector<T> &da) {
    for (int i = 0;i < da.size();i++) {
        if (i == da.size() - 1) std::cout << da[i];
        else std::cout << da[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
    for (int i = 0;i < da.size();i++) vdeb(da[i]);
    std::cout << std::endl;
}

long long pow(long long n, long long p, long long k) {//n^k(mod p)
    if (!k) return 1;
    long long a = pow(n,p, k>>1);
    a = a * a%p;
    if (k & 1) a = a * n%p;
    return a;
}
void euclid(long long &a, long long &b, long long p) { // a>=b A*b+B*(a-a/b*b)=1
    if (a == 1) {
        a = 1;
    }
    else {
        long long A = b, B = a % b;
        euclid(A, B, p);
        b = (A - (p + a / b) % p * B % p + p) % p;
        a = B;
    }
}
long long rev(long long n, long long p) {//nの逆元 n*x-p*y=1
    //long long q = p;
    //euclid(p, n, p);
    //return n % q;
    return pow(n,p,p-2);
}
long long bino(long long n, long long m, long long p) {//nCm(mod p)
    long long ans = 1, div = 1;
    for(int i = 0;i < m; i++){
        ans = (n - i) * ans % p;
        div = div * (i +1) % p;
    }
    return ans * rev(div, p) % p;
}
struct modint {
    long long num;
    long long p;
    modint() {
        num = 0;
        p = 998244353;
    }
    modint(int x) {
        p = 998244353;
        num = (long long)x%p;
    }
    modint(long long x) {
        p = 998244353;
        num = x % p;
    }
    modint operator+(const modint &other) {
        modint ret;
        ret.p = p;
        ret.num = (num + other.num) % p;
        return ret;
    }
    modint operator+(const long long &other) {
        modint ret;
        ret.p = p;
        ret.num = (num + (other%p)) % p;
        return ret;
    }
    modint operator-(const modint &other) {
        modint ret;
        ret.p = p;
        ret.num = (num - other.num + p) % p;
        return ret;
    }
    modint operator-(const long long &other) {
        modint ret;
        ret.p = p;
        ret.num = (num - (other%p) + p) % p;
        return ret;
    }
    modint operator*(const modint &other) {
        modint ret;
        ret.p = p;
        ret.num = (num*other.num) % p;
        return ret;
    }
    modint operator*(const long long &other) {
        modint ret;
        ret.p = p;
        ret.num = (num*(other%p)) % p;
        return ret;
    }
    modint operator/(const modint &other) {
        modint ret;
        ret.p = p;
        ret.num = (num*rev(other.num, p)) % p;
        return ret;
    }
    modint operator/(const long long &other) {
        modint ret;
        ret.p = p;
        ret.num = (num*rev(other%p, p)) % p;
        return ret;
    }
    void operator+=(const long long &other) {
        num = (num + other) % p;
    }
    void operator+=(const modint &other) {
        num = (num + other.num) % p;
    }
    void operator-=(const long long &other) {
        num = (num - other + p) % p;
    }
    void operator-=(const modint &other) {
        num = (num - other.num + p) % p;
    }
    void operator*=(const long long &other) {
        num = (num*other) % p;
    }
    void operator*=(const modint &other) {
        num = (num*other.num) % p;
    }
};
std::ostream& operator<<(std::ostream &os, const modint &x){
    std::cout << x.num;
    return os;
}

using namespace std;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(a%b) return gcd(b, a%b);
    return b;
}

modint comb(ll n, ll x){
    modint ret(1), div(1);
    rip(i,x,0){
        ret *= n-i;
        div *= i+1;
    }
    return ret/div;
}

int main(){
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    ll g = gcd(a, b);
    if(k%g){
        cout << 0 << endl;
        return 0;
    }
    if(a < b) swap(a,b);
    ll kk = k/g;
    a /= g;
    b /= g;
    ll aa = 0, bb = (kk-aa*a)/b;
    while((kk-aa*a)%b || !(aa <= n && 0 <= aa && 0 <= bb && bb <= n)){
        aa++;
        bb = (kk-aa*a)/b;
        if(aa > n || bb < 0){
            cout << 0 << endl;
            return 0;
        }
    }
    bb = (kk-aa*a)/b;
    modint ans;
    modint an = comb(n, aa), bn = comb(n, bb);
    bool ju = false;
    while(aa <= n && bb >= 0){
        if(ju){
            rip(i,b,0){
                an = an/(aa-i);
                an *= n-aa+i+1;
            }
            rip(i,a,0){
                bn *= (bb+i+1);
                bn = bn/(n-bb-i);
            }
        }
        else ju = true;
        ans += an*bn;
        aa += b;
        bb -= a;
    }
    cout << ans << endl;
}