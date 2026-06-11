#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

auto factoring = [](i64 x){
    int sq = sqrt(x) + 1;
    vector<int> ret;
    if(x == 1){
        ret.emplace_back(1);
        return ret;
    }
    for(i64 i = 2; i < sq; ++i)
        while(x % i == 0){
            ret.emplace_back(i);
            x /= i;
        }
    if(x != 1)
        ret.emplace_back(x);
    return ret;
};


template <i64 mod = MOD>
struct ModInt{
    i64 p;

    ModInt() : p(0){}
    ModInt(i64 x){p = x >= 0 ? x % mod : x + (-x + mod - 1) / mod * mod;}

    ModInt& operator+=(const ModInt& y){p = p + *y - ((p + *y) >= mod ? mod : 0); return *this;}
    ModInt& operator-=(const ModInt& y){p = p - *y + (p - *y < 0 ? mod : 0); return *this;}
    ModInt& operator*=(const ModInt& y){p = (p * *y) % mod; return *this;}
    ModInt& operator%=(const ModInt& y){if(y)p %= *y; return *this;}

    ModInt operator+(const ModInt& y) const{ModInt x = *this; return x += y;}
    ModInt operator-(const ModInt& y) const{ModInt x = *this; return x -= y;}
    ModInt operator*(const ModInt& y) const{ModInt x = *this; return x *= y;}
    ModInt operator%(const ModInt& y) const{ModInt x = *this; return x %= y;}

    friend ostream& operator<<(ostream& stream, const ModInt<mod>& x){
        stream << *x;
        return stream;
    }

    friend ostream& operator>>(ostream& stream, const ModInt<mod>& x){
        stream >> *x;
        return stream;
    }

    ModInt& operator++(){p = (p + 1) % mod; return *this;}
    ModInt& operator--(){p = (p - 1 + mod) % mod; return *this;}

    bool operator==(const ModInt& y) const{return p == *y;}
    bool operator!=(const ModInt& y) const{return p != *y;}

    const i64& operator*() const{return p;}
    i64& operator*(){return p;}

};

using mint = ModInt<>;




signed main(){
    int n;
    cin >> n;
    vector<int> v(200, 0);
    for(int i = 0; i < n; ++i){
        auto res = factoring(i + 1);
        for(auto y : res)
            ++v[y];
    }
    vector<vector<int>> dp(201, vector<int>(76, 0));
    dp[2][1] = 1;
    for(int i = 2; i < 200; ++i){
        for(int j = 1; j < 76; ++j){
            if(dp[i][j] == 0)
                continue;
            for(int k = 0; k <= v[i]; ++k){
                if(j * (k + 1) <= 75){
                    dp[i + 1][j * (k + 1)] += dp[i][j];
                }
            }
        }
    }
    cout << dp.back()[75] << endl;
}
