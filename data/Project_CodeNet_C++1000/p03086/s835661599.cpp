#include <bits/stdc++.h>
using namespace std;



int main() {
    string s;
    cin>>s;
    
    int  i,ans=0,count=0;
    for(i=0;i<s.size();i++){
       if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C') count++;
      	else count=0;
      ans=max(ans,count );
     }
     	cout << ans << endl;
     

    return 0;
}