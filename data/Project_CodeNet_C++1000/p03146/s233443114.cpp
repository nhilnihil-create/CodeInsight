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
void input(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void swap(int& a, int& b){
	int t=a;
	a = b;
	b = t;
}


void solveTest(){
	int s;
	cin>>s;
	set<int> st;
	st.insert(s);
	int x=2;
	while(1){
		if(s%2==0){
			s = s/2;
		}
		else {
			s = 3*s+1;
		}
		if(st.find(s)!=st.end()){
			cout<<x<<endl;
			return ;
		}
		st.insert(s);
		x++;
	}
	return ;
}

int main(){
	fastio();
	//input();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();

	}
	
	return 0;
}
