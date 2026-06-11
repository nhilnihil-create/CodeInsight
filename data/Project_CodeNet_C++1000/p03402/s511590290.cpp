/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    int a, b;
    cin >> a >> b;
    vector<string> s(100);

    rep(i, 100){
        s[i].resize(100);
        rep(j, 100){
            if(i < 50){
                s[i][j] = '#';
            } else {
                s[i][j] = '.';
            }
        }
    }
    bool f = false;
    a--;
    if(a != 0){
        for(int i = 0; i < 50; i += 2){
            for(int j = 0; j < 50; j += 2){
                s[i][j] = '.';
                a--;
                if(a == 0){
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
    }


    f = false;
    b--;
    if(b != 0){
        for(int i = 99; i >= 50; i -= 2){
            for(int j = 99; j >= 50; j -= 2){
                s[i][j] = '#';
                b--;
                if(b == 0){
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100){
        cout << s[i] << endl;
    }
}