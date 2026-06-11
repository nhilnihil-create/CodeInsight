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
    string s;cin >>s;
    int n=s.size();
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=s[i]-'0';
    }
    int ans=max(sum,(n-1)*9+(s[0]-'1'));
    cout <<ans <<endl;
}
