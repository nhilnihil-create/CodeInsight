typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll l;
    std::cin >> l;
    ll nowl = l;
    ll r = 0;
    while(nowl/2){
        r++;
        nowl/= 2;
    }
    
    // L = 10101011101101
    //     01111111111111
    ll n = r+1;
    ll m = 0;
    vector<string> result;
    for (int i = n-1; i >= 1; i--) {
        ll x = l-(ll)pow(2,i-1);
        if(x >= (ll)pow(2,r)){
            l-=(ll)pow(2,i-1);
            m++;
            result.push_back( to_string(i)+" "+to_string(n)+" "+to_string(x) );
        }
    }
    for (int i = 1; i < n; i++) {
        m+=2;
        result.push_back( to_string(i)+" "+to_string(i+1)+" "+to_string( (ll)pow(2,i-1) ) );
        result.push_back( to_string(i)+" "+to_string(i+1)+" "+to_string(0) );
    }
    
    std::cout << n<<" " <<m<< std::endl;
    
    for (auto e : result) {
        std::cout << e << std::endl;
    }
}
