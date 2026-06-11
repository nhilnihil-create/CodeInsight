#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N,H,W;
	cin>>N>>H>>W;
	vector<int>A(N);
	vector<int>B(N);
	int ans=0;
	rep(i,N){
		cin>>A.at(i)>>B.at(i);
		if(A.at(i)>=H&&B.at(i)>=W){
			ans++;
		}
	}
	cout<<ans<<endl;
return 0;}

/*compile
g++ code.cpp
./a.out
run*/