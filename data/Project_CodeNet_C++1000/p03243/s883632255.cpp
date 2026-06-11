#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define cool ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define MAX 1000001
#define mod 1000000007
#define pie 3.14159265358979323846
void solve()
{
	int n;
	cin>>n;
	if(n<=111)
	cout<<"111";
	else if(n>111&&n<=222)
	cout<<"222";
	else if(n>222&&n<=333)
	cout<<"333";
	else if(n>333&&n<=444)
	cout<<"444";
	else if(n>444&&n<=555)
	cout<<"555";
	else if(n>555&&n<=666)
	cout<<"666";
	else if(n>666&&n<=777)
	cout<<"777";
	else if(n>777&&n<=888)
	cout<<"888";
	else if(n>888&&n<=999)
	cout<<"999";
}
int main()
{ 
    cool;
    int t;
    //cin>>t;
    t=1;
    while(t--){
    	solve();
	}
    return 0;
}
