#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	string S;
	cin>>S;
	int count=0;
	rep(i,S.size()){
		if(S.at(i)=='o'){
			count++;
		}
	}
	if(count+(15-S.size())>=8){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
return 0;}

/*compile
g++ code.cpp
./a.out
run*/