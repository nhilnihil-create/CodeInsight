#include<bits/stdc++.h>
using namespace std;
main(){
long long int n;
cin>>n;
double p[n];
for(int i=0;i<n;i++){cin>>p[i];}
double ans[n+1];
ans[0]=1;
//memset(ans,0,sizeof(ans));
for(int i=1;i<=n;i++)for(int j=i;j>=0;j--){
	if(j==0)ans[j]=ans[j]*(1-p[i-1]);
	else{


		if(j==i)ans[j]=ans[j-1]*p[i-1];
		else{
ans[j]=ans[j-1]*p[i-1]+ans[j]*(1-p[i-1]);
}}
//cout<<ans[j];
//cout<<" "<<j<<endl;




}
double   sum=0;
for(int i=0;i<=n;i++)
{
if(i>(n-i))sum+=ans[i];
}

printf("%.10f",sum);

}
