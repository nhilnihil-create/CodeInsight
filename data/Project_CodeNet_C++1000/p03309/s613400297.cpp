#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pb push_back

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll sum = 0;
	ll copy[n];
	for(int i=0;i<n;i++){
	copy[i]=	(arr[i] - (i+1));
	}
	sort(copy,copy+n);
	sum = copy[n/2];
	ll res=0;
	for(int i=0;i<n;i++)
		res += abs(arr[i]-(i+1)-sum);
	cout<<res<<"\n";

}	


/*1 1 1 1 2 3 4
0 -1 -2 -3 -3 -3 -3
2  1  0 -1  -1 -1 -1*/