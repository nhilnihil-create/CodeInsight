#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int x[27];
    int y[27];
    int ans=0;
    for(int i=1;i<n;i++){
        int tmp=0;
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        for(int j=0;j<i;j++)x[(s[j]-'a')]++;
        for(int j=i;j<n;j++)y[(s[j]-'a')]++;
        for(int j=0;j<26;j++)if(x[j]>0 && y[j]>0)tmp++;
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}