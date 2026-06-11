// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	string s;
	cin>>s;
	int n=s.size();
	vector<int> v;
	for(int i=0;i<n;i++){
		if(s[i]=='W'){
			v.push_back(i);
		}
	}
	ll sum=0;
	for(int i=0;i<v.size();i++){
		sum += v[i]-i;
	}
	cout<<sum<<endl;
	//cout<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}