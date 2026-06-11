#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define PB push_back
const ll modd=1e9+7;

int main(){

int a,b;
cin>>a>>b;
int ans=0,i,j;
int pl=0;
for(i=a;i<=b;++i){
        j=i;
        while(j){
            pl*=10;pl+=j%10;j/=10;
        }
if(i==pl)ans++;
pl=0;

}
cout<<ans<<endl;


return 0;

}
