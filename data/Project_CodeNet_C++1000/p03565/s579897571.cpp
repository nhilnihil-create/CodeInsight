#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main(void){
   
string s,t;
cin>>s>>t;


int sl= s.length();
int tl= t.length();
int i=0,j=0,l=-1;
for( i=0;i<(sl-tl+1);i++){
  //  cout<<s[i];
  bool ok=true;
    for( j=0;j<tl;j++){
        if(s[i+j]!='?' && s[i+j]!=t[j])
            ok=false;
        
    }
    if(ok){
        l=i;
    }
    
}
if(l!=-1)
    {
        for(int k=0;k<tl;k++){
            s[l+k]=t[k];
        }
        for(int i=0;i<sl;i++){
            if(s[i]=='?')
                s[i]='a';
        }
        cout<<s<<endl;
        return 0;
    }
cout<<"UNRESTORABLE";
    
}
