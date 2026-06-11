#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define debug(var)  do{std::cout << #var << " : "; view(var);}while(0)
using namespace std;
typedef long long ll;
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){for(const auto& v : vv){ view(v); } }
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void viewarr(T arr[], int n) { for(int i = 0; i < n; ++i) std::cout << arr[i] << " "; std::cout << std::endl; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    rep(i,K) {
        if(i % 2 == 0){
        if(A % 2 == 1) --A;
        B += A/2;
        A /= 2;
    }else{
        if(B % 2 == 1) --B;
        A += B/2;
        B /= 2;
    }}
    printf("%d %d\n", A, B);
    return 0;
}
