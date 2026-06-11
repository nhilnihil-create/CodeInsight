#include<bits/stdc++.h>
using namespace std;
int e[300005];
int w[300005];
int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        w[i+1]=w[i]+(s[i]=='W');
        e[n-i-1]=e[n-i]+(s[n-i-1]=='E');
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        ans=min(ans,w[i]+e[i+1]);
    }
    cout << ans << endl;
}