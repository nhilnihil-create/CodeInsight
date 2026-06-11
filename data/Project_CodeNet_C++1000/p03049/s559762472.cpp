#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0,b=0,c=0,ans=0;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
        int k = s[i].size()-1;
        if(s[i][0]=='B') a++;
        if(s[i][k]=='A') b++;
        if(s[i][0]=='B'&&s[i][k]=='A') c++;
        for(int j=0;j<k;j++){
            if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
        }
    }
    a-= c;
    b-= c;
    if(c==0) ans += min(a,b);
    else{
        if(a+b>0) ans += c+min(a,b);
        else ans += c-1;
    } 
    cout << ans << endl;
}