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
    string s,t;cin>>s>>t;
    bool ans = false;
    rep(i,s.size()){
        if(s==t) ans=true;
        s=s.back()+s.substr(0,s.size()-1);
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}
