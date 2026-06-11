#include <bits/stdc++.h>
using namespace std;
const int N=410;

int a[N],res;
void search1(int l,int r)
{
	if(l>r)return ;
	while(a[l]==0)
	{
		l++;
		if(l>r)return ;
	}
	while(a[r]==0){
		r--;
		if(l>r)return ;
	}

	int mid,min1=1000;
	for(int i=l;i<=r;i++)
	{
		if(a[i]<=min1)
		{
			min1=a[i];
			mid=i;
		}
	}
	res+=a[mid];
	for(int i=l;i<=r;i++){a[i]=a[i]-min1;}


	search1(l,mid-1),search1(mid+1,r);

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	search1(0,n-1);
	cout<<res;
}
