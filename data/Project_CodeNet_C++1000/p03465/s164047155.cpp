#include<bits/stdc++.h>
#define sp ' '
using namespace std;

int N,A;
bitset<4000001> b;

int main(){
	cin>>N;
	b[0]=1;
	for(int i=0;i<N;++i){
		cin>>A;
		b|=(b<<A);
	}
	int c=b.count()/2;
	for(int i=1;;++i){
		if(b[i])--c;
		if(!c){
			cout<<i<<endl;
			return 0;
		}
	}
}
