#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
int a,now=-1,n;
cin>>n;
int res=-1;
while(n--){
cin>>a;
if(a>now+1){
cout<<-1<<endl;
return 0;
}
if(a>now)res++;
else res+=a;
now=a;
}
cout<<res<<endl;
}
