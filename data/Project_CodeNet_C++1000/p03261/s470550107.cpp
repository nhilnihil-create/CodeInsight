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
	int n;
	cin>>n;
	set<string> st;
	vector<string> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		st.insert(s);
		v.push_back(s);
	}
	if(st.size()!=n){
		cout<<"No"<<endl;
		return;
	}
	int flag=0;
	for(int i=1;i<n;i++){
		string p = v[i-1];
		string c= v[i];
		if(p[p.size()-1]!=c[0]){
			flag=1;
			break;
		}
	}
	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
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