#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
string s;
cin>>s;
int ans=0;
rep(i,s.size()){
    int count=0;
    for(int j=i;j<s.size();j++){
        
    if(!(s[j]=='A'||s[j]=='G'||s[j]=='C'||s[j]=='T')){
    break;
    }
    count++;
   
    
    }
 ans=max(ans,count);
}
cout<<ans;
}


