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
    int r, d, x;cin>>r>>d>>x;
    rep(i,10){
        x = r*x-d;
        cout<<x<<endl;
    }

}
