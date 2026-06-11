#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i< int (n); i++)
int main(){

int n;
string s;
cin >> n >> s;
int w[1000000]={0}, e[1000000]={0}; 
if(s[0]=='W') w[0]++;
else e[0]++;
for(int i=1; i<n; i++) {
    if(s[i]=='W') w[i]=w[i-1]+1; // i+1人目までのWの人数和
    else w[i]=w[i-1];
}
for(int i=1; i<n; i++){
    e[i]=i+1-w[i]; // i+1人目までのEの人数和
}

int ans=e[n-1];
for(int i=1; i<n; i++){
    ans=min(ans, w[i-1]+e[n-1]-e[i]);
    //cout << ans << endl;
}
cout << ans << endl;
//rep(i,n) cout << w[i];
//cout << endl;
//rep(i,n) cout << e[i];
//cout << endl;

}