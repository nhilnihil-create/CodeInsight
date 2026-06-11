#include<bits/stdc++.h>
using namespace std;
int a[111111],b[111111];
int cnt[111111];
int ptr;
long long tot;
int ans;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		if(a[i]<b[i]){
			tot+=b[i]-a[i];
			ans++; 
		}
	long long qwe=0;
	for(int i=0;i<n;i++)
		if(a[i]>b[i]){
			cnt[ptr++]=a[i]-b[i];
			qwe+=a[i]-b[i];
		}
	if(qwe<tot){
		cout<<-1<<endl;
		return 0;
	}
	if(tot==0){
		cout<<0<<endl;
		return 0;
	}
	sort(cnt,cnt+ptr);
	reverse(cnt,cnt+ptr);
	for(int i=0;i<ptr;i++)
		if(tot<=cnt[i]){
			ans++;
			break;
		}
		else{
			ans++;
			tot-=cnt[i];
		}
	cout<<ans<<endl;
	return 0;
}