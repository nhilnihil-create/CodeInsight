#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int ans = 0;
    string s; cin >> s;
    string t = "keyence";
    
    if(s == t){
        put("YES");
        return 0;
    }

    for(int i = 0; i < t.size(); i++){
        for(int j = i+1; j < s.size(); j++){
            //put(s.substr(0,i) + s.substr(j,s.size()-1));
            if(t == s.substr(0,i) + s.substr(j,s.size())){
                ans++;
            }
        }
    }

    put((ans?"YES":"NO"));
}