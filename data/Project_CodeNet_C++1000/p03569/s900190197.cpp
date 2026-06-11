#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T; cin >> S; T=S;
    reverse(T.begin(),T.end());
    int n=S.size(),ans=0,ok=1;
    for (int i=0,j=0;i+j<n;++i,++j){
        if (S[i]==T[j]) continue;
        if (S[i]=='x'){
            int now=i;
            while(S[i]=='x') ++i;
            if (S[i]==T[j]) ans+=i-now;
            else ok=0;
        } else if (T[j]=='x'){
            int now=j;
            while(T[j]=='x') ++j;
            if (S[i]==T[j]) ans+=j-now;
            else ok=0;
        } else ok=0;
    }
    cout << (ok?ans:-1) << '\n';
}