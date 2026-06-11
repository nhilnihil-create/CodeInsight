#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    int ans = 0;
    if(s[0] == '2') ans++;    
    if(s[1] == '2') ans++;    
    if(s[2] == '2') ans++;    
    if(s[3] == '2') ans++;    

    cout << ans << endl;

    return 0;
}

