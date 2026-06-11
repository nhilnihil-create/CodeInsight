#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    string s1, s2; cin >> s1 >> s2;
    string s3 = s2, s4 = s1;
    reverse(all(s3));
    reverse(all(s4));
    if(s3 == s1 && s2 == s4) cout << "YES" << endl;
    else cout << "NO" << endl;
}