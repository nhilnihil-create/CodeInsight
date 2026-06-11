#include <bits/stdc++.h>
#define ll long long 
#define v vector<int> 
using namespace std; 
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); 
string s; 
cin>>s; 
int i,n=s.length(),c=0,j,ans=0; 
for(i=0;i<n;i++){
if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
    c++;
    for(j=i+1;j<n;j++){
        if(s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T'){c++;}
        else{break;}
    }
    ans=max(ans,c);
    c=0;
}
else{ans=max(ans,c);}
}
cout<<ans <<"\n";
}