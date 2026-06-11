#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;

const int mod = 1000000007;
struct mint{
    ll x;
    mint(ll x=0):x(x%mod){}
    mint& operator+=(const mint a){
        if ((x+= a.x) >= mod) x-= mod;
        return *this;
    }
    mint& operator-=(const mint a){
        if ((x+= mod - a.x) >= mod) x-= mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x*=a.x)%=mod;
        return *this;
    }
    mint operator+(const mint a) const{
        mint ans(*this);
        return ans+= a;
    }
    mint operator-(const mint a) const{
        mint ans(*this);
        return ans-= a;
    }
    mint operator*(const mint a) const{
        mint ans(*this);
        return ans*= a;
    }
};



int main(){
    int N;
    string s;
    cin >> N >> s;
    int cr = 0;
    int cb = 0;
    rep(i,N){
        if (s[i] == 'R'){
            cr++;
        }
        else{
            cb++;
        }
    }
    cout << (cr>cb?"Yes":"No");
}