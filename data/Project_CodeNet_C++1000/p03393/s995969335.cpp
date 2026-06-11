#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    string w = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    int n=s.size();
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << "\n";
        return 0;
    }
    if(n==26){
        string t,ss;
        ss=s;
        next_permutation(s.begin(),s.end());
        rep(i,n){
            if(s[i]==ss[i]){
                t+=s[i];
                continue;
            }
            else{
                t+=s[i];
                cout << t << "\n";
                return 0;
            }
        }
        cout << -1 << "\n";
        return 0;
    }
    rep(i,26){
        bool ok=true;
        rep(j,n){
            if(w[i]==s[j]) ok=false;
        }
        if(ok){
            s+=w[i];
            cout << s << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}   