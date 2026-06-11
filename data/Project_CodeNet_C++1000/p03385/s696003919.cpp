#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    unordered_set<char>s;
    for (int i = 0; i < 3; ++i) {
        char c;cin >>c;
        s.insert(c);
    }
    if(s.size()==3)puts("Yes");
    else puts("No");
    return 0;
}