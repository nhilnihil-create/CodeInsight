#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define de cout<<"debuglandınız\n";
#define md 1000000007
ll int n,m,a,ar[105],i,ans,su=1;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for(i=0;i<n;i++)cin >> ar[i];
	ar[n]=n+5;
	for(i=0;i<n;i++){
		if(ar[i]==ar[i+1])su++;
		else{
			ans+=su/2;
			su=1;
		}
	}
	cout<<ans;
	return 0;
}