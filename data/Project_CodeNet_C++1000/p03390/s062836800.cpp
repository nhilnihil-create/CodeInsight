#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "]"; return os; }


// import here

LL solve(LL a, LL b){
    if(a > b) swap(a, b);
    // now a <= b
    if(b-a <= 1){
        return (a-1) * 2;
    }
    LL c = sqrt(a*b);
    if(c*c >= a*b) --c;
    if(c * (c+1) >= a*b){
        return c*2 - 2;
    }else{
        return c*2 - 1;
    }
}

int main(){
    LL q;
    cin >> q;
    vector<LL> a(q), b(q);
    for(LL i = 0; i < q; ++i){
        cin >> a[i] >> b[i];
        cout << solve(a[i], b[i]) << endl;
    }
    return 0;
}

