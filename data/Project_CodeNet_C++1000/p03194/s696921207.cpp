#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

map< int64_t, int64_t > prime_factor(int64_t n) {
    map< int64_t, int64_t > ret;
    for(int64_t i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

int main(){
    int64_t n, p;
    cin >> n >> p;
    int64_t out = 1;
    for(auto e: prime_factor(p)){
        while(e.second >= n){
            out *= e.first;
            e.second -= n;
        }
    }
    cout << out << endl;
    return 0;
}
