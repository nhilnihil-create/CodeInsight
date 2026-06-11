#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

constexpr int MOD = 1000000007;
ll modpow(ll n, ll r, ll mod) {
    if(r == 0) return 1;
    if(n == 0) return 0;
    if(r % 2 == 0) {
        ll tmp = modpow(n, r / 2, mod);
        return tmp * tmp % mod;
    }
    else {
        return n * modpow(n, r - 1, mod) % mod;
    }
}

int main(){
    ll r, D, x;
    read(r, D, x);
    for(int i = 0; i < 10; i++){
        x = r * x - D;
        cout << x << endl;
    }
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//