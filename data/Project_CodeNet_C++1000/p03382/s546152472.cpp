#include <iostream>
using namespace std;
int arr[100005];
int main()
{
	int n,mx=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		mx=max(mx,arr[i]);
	}
	int b=-1;
	for (int i=0;i<n;i++)
	{
		if (arr[i]!=mx && min(arr[i],mx-arr[i])>min(b,mx-b))
		b=arr[i];
	}
	printf("%d %d",mx,b);
}