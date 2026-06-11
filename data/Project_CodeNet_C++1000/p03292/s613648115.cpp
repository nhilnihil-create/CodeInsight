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
	long A[3];
	for(int i=0;i<3;i++){
		cin>>A[i];
	}
	
	sort(A,A+3);
	long ans = 0;
	for(int i=1;i<3;i++){
		ans+=abs(A[i]-A[i-1]);
	}
	cout<<ans<<"\n";
}
/*
7
1 1 1 1 2 3 4
1  2  3  4  5  6  7
0 -1 -2 -3 -3 -3 -3
-3 -3 -3 -3 -2 -1 0
-3 -2 -1 0 0 0 0
A - ( b + i )
A - i = b ;
*/
