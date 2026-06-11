#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	string S;
	int w;
	cin>>S>>w;
	rep(i,S.size()){
		if(i%w==0){
			cout<<S.at(i);
		}
	}
return 0;}

/*compile
g++ code.cpp
./a.out
run*/