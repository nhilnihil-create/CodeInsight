#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
int ans;
if(a<b) {
    ans=b;
    b=b-1;
}
else {
    ans=a;
    a=a-1;
}
cout<<ans+max(a,b)<<endl;
return 0;
}