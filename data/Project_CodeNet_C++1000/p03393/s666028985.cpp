#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    cin>>s;

    int n=s.size();

    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout<<-1<<endl;
        return 0;
    }

    if(n==26){
        string t=s;
        next_permutation(all(s));
        string ans="";
        rep(i,n){
            ans+=s[i];
            if(s[i]>t[i]) break;
        }

        cout<<ans<<endl;
        return 0;
    }
    vector<int> cnt(26,0);
    rep(i,n){
        cnt[s[i]-'a']++;
    }

    rep(i,26){
        if(cnt[i]==0){
            string ans=s+char('a'+i);
            cout<<ans<<endl;
            return 0;
        }
    }
}