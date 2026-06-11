#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N;
	string s;
	cin>>N>>s;
	int bc=0,rc=0;
	rep(i,N){
		if(s.at(i)=='B'){
			bc++;
		}else{
			rc++;
		}
	}
	if(rc>bc){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
return 0;}

/*compile
g++ code.cpp
./a.out
run*/