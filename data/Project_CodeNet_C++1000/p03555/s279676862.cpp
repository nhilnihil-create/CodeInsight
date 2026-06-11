#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    string s1,s2; cin>>s1>>s2;
    if(s1[0]==s2[2] && s1[2]==s2[0] && s1[1]==s2[1]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}