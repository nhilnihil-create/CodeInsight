#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N,A,B;
	cin>>N>>A>>B;
	vector<int>P(N);
	int s=0,m=0,l=0;
	rep(i,P.size()){
		cin>>P.at(i);
		if(P.at(i)<=A){
			s++;
		}else if(A+1<=P.at(i)&&P.at(i)<=B){
			m++;
		}else if(B+1<=P.at(i)){
			l++;
		}else{}
	}
	cout<<min(s,min(m,l))<<endl;;

return 0;}

/*compile
g++ code.cpp
./a.out
run*/