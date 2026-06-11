#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    string s,t; cin >> s >> t;
    vector<char> v1,v2;
    for(int i = 0;i < s.length();i++){
        v1.push_back(s[i]);
    }
    
    string ans1;
    for(int i = 0;i < s.length();i++){
        ans1 += v1[i];
    }
    
    for(int i = 0;i < t.length();i++){
        v2.push_back(t[i]);
    }
    
    string ans2;
    for(int i = 0;i < t.length();i++){
        ans2 += v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<char>());
    v1 < v2 ? cout << "Yes" : cout << "No";
}
