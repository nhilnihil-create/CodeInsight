#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	double N;
	cin>>N;
	double ave=0;
	vector<int>a(N);
	rep(i,N){
		cin>>a.at(i);
		ave+=a.at(i);
	}
	ave=ave/N;
	double min=abs(a.at(0)-ave);
	//cout<<abs(a.at(0)-ave);
	//cout<<min;
	int minn=0;
	rep(i,N){
		if(abs(a.at(i)-ave)<min){
			min=abs(a.at(i)-ave);
			minn=i;
		}
	}
	cout<<minn<<endl;
return 0;}

/*compile
g++ code.cpp
./a.out
run*/