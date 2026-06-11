#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int a,b,c,d;
cin>>a>>b>>c>>d;
int ans=0;
for(int i=0;i<3001;i++){
for(int j=0;j<3001;j++){
if((d-a*i-b*j)%c==0 && (d-a*i-b*j)>=0){
    ans++;
}
    
}

}
cout<<ans<<endl;
}