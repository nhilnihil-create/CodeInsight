#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;



int main(){
    string s;
    cin >> s;
    ll n=s.size();
    for(ll i=1;i<n;i++){
        if(s[i-1]=='B'&&s[i]=='C'){
            s[i-1]='D';
            s[i]='d';
        }
    }
    ll res=0,counta=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='B'||s[i]=='C') counta=0;
        else if(s[i]=='A') counta++;
        else if(s[i]=='D') res+=counta;
    }
    cout << res << endl;
    return 0;
}  
