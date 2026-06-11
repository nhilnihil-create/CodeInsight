#include<bits/stdc++.h>
using namespace std;
int main()
{ string s; int cnt=0;
cin>>s;
int n=s.size() ;
for(int i=0 ; i<n ; i++){
int d= s[i]-'0' ;
if(d==1)
cnt++ ; }
cout<< cnt << "\n";

return 0;

}
