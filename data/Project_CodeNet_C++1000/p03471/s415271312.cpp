#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,y,i,j,k,ans,flag=0;
 cin>>n>>y;
	for(i=0;i<=n;i++){
    for(j=0;j<=n-i;j++){
    		ans=(10000*i)+(5000*j)+(1000*(n-i-j));
     	if(ans==y){flag=1;break;}
    }
    if(flag) break;
	}
 if(flag) cout<<i<<" "<<j<<" "<<n-i-j;
 else cout<<-1<<" "<<-1<<" "<<-1;
}