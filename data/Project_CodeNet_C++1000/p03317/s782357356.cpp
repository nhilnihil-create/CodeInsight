/*
Author : Devil088
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define sep cout<<"\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
int main(){
	long n,k;
	cin>>n>>k;
	long A[n];
	long m = 100000000;
	for(int i=0;i<n;i++){
		cin>>A[i];
		m = min(m,A[i]);
	}
	long x = 0,ans = 0;
	for(int i=0;i<n;i++){
		if(A[i] == m){
		}else x++;
	}
	cout<<ceil(x/(float)(k-1))<<"\n";
}
/*
10
3 3 3 3 3 1 3 3 3 3 3 
0 1 2 3 4 5 6 7 8 9 10
* 
* 
8 3
7 3 1 1 1 1 2 5
3 5 2 3 4 1
0 1 2 3 4 5 6 7
* */
