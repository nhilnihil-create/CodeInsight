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
    vector<string>s(3);
    for (int i = 0; i < 3; ++i) {
        cin >>s[i];
    }
    for (int i = 0; i < 3; ++i) {
        cout <<s[i][i];
    }
    cout <<endl;
    return 0;
}