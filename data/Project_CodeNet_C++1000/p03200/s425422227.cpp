#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    int n=s.size();
    ll ans=0;
    int b=0;
    int i=0;
    for (int i=0; i<n; i++){
        if(s[i]=='B') b++;
        if(s[i]=='W') ans+=b;
    }
    cout << ans << endl;
}