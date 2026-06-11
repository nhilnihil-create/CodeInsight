#pragma region noncode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SORT(v) sort(all(v))
#define TROS(v) sort(all(v), std::greater<Type>());
#pragma endregion

int main() {
    // template
    string s;cin>>s;
    int res = 700;
    rep(i,3){
        if(s.at(i)=='o') res+=100;
    }
    cout<<res<<endl;
}
