#include<bits/stdc++.h>
using namespace std;

long long n,q,l,r;
string s;
char t[1000000],d[1000000];

int main(){

	cin>>n>>q>>s;
	
	for(int i=0;i<q;i++){
	    cin>>t[i]>>d[i];
    }
    
    l=-1;
    r=n;
    
    for(int i=q-1;i>=0;i--){
        
        if(d[i]=='L'){
            if(l+1<n && s[l+1]==t[i])l++;
        }
        else{
            if(l>=0 && s[l]==t[i])l--;
        }
        
    }
    
    
    for(int i=q-1;i>=0;i--){
        
        if(d[i]=='R'){
            if(r-1>=0 && s[r-1]==t[i])r--;
        }
        else{
            if(l<n && s[r]==t[i])r++;
        }
        
    }
    
    
    cout<<max(r-l-1ll,0ll)<<"\n";

return 0;
}
