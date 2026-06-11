#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    string s, t;    cin >> s >> t;
    int n=s.size();
    vector<set<char>> key(26);

    for(int i=0; i<n; i++)
        key[t[i]-'a'].insert(s[i]);

    string ans="Yes";

    for(int i=0; i<26; i++)
        if(1<key[i].size()) ans = "No";
        
    key = vector<set<char>> (26);

    for(int i=0; i<n; i++)
        key[s[i]-'a'].insert(t[i]);
    for(int i=0; i<26; i++)
        if(1<key[i].size()) ans = "No";
    
    cout << ans << endl;

}