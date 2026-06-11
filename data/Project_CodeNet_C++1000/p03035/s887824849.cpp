#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
int ans;
if(a<=5) ans=0;
else if(a>5&&a<=12) ans=b/2;
else ans=b;
cout<<ans<<endl;
}