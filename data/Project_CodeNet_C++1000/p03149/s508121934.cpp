//do not think about past and stay in this moment
//organize and work - Abhinav IIITA
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define rf(i,x,n) for(int i=x-1;i>=n;--i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end() 
void print(int arr[],int n){
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int fre[10];
int32_t main()
{
	
	int n; cin>>n; fre[n]++;
	cin>>n; fre[n]++;
	cin>>n; fre[n]++;
	cin>>n; fre[n]++;
	if(fre[1]==1 && fre[9]==1 && fre[7]==1 && fre[4]==1)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
