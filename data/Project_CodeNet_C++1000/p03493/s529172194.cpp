
#include <bits/stdc++.h>
using namespace std;

int main()
{
string S;    
cin>>S;
    
if (S[0]=='1'  && S[1]=='1' && S[2]=='1'){
 cout<<3<<endl;   
}
else if(S[0]=='0' && S[1]=='0' && S[2]=='0'){
 cout<<0<<endl;   
}
else if( (S[0]=='1' && S[1]=='0' && S[2]=='0') ||
       (S[0]=='0' && S[1]=='1'  && S[2]=='0') ||         
       (S[0]=='0' && S[1]=='0'  && S[2]=='1') ){
 cout<<1<<endl;   
}
else  {
cout<<2<<endl;
}
}

