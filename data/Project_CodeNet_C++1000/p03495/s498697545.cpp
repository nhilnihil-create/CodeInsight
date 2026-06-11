#include<bits/stdc++.h>
#define ll long long
const int N=200005;
using namespace std;
bool cmp(int a,int b)
{
	return a>b; 
}
int k,n,a[N],b[N];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	    cin>>a[i],b[a[i]]++;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=k;i++) n-=b[i];
	cout<<n;
    return 0;
}