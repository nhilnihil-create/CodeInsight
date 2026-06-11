#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    string S;
    cin>>S;
    int min = 1000;
    FOR(i, 2, S.length()){
        min = std::min(abs(753 - stoi(S.substr(i-2, 3))), min);
    }

    cout << min << endl;
}
