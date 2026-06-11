#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char s[204];
    cin>>s;
    n=strlen(s);
    int k=0;
    for(int i=0;i<n;i++) if(s[i]=='o') k++;
    if(k+15-n>=8) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}


