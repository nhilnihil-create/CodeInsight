#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    vector<int> c(26,0), e(26,0);
    string s;   cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){print(-1); return 0;}
    int l = s.length();
    for(int i=0; i<l; i++)  c[s[i] - 'a']++;
    for(int i=0; i<26; i++) if(c[i] == 0){
        s += char(i + 'a');
        print(s);
        return 0;
    }
    map<string,int> mp;
    string t;
    for(int i=0; i<l; i++){
        e[s[i] - 'a'] = 1;
        for(int j=0; j<26; j++){
            if(e[j] == 0) t = s.substr(0,i) + char(j + 'a');
            mp[t] = 1;
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++) if(it -> first > s){print(it -> first); return 0;}
}