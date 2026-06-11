#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair<int,int> pi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define re(i,a,b) for(ll i=a;i<b;i++)
//add below to remove endl in input just before getline()
//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
int twos(int a,int c){
	for(int i=2;i<=a;i*=2){
		if(a%i==0)c++;
		}
	return c;}
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n,c=0;
	cin>>n;int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		c=twos(a[i],c);
		}
	cout<<c;
	

	
return 0;}
