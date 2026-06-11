#include <bits/stdc++.h>
using namespace std;

int cou(char a,char b,char c){
	if(a!=b && b!=c && a!=c){
		return 1;
	}
	else if(a==b && b==c&& c==a){
		return 3;
	}
	else{
		return 2;
	}
}

int main(){
	int N;
	string A,B,C;
	cin>>N>>A>>B>>C;
	int count=0;
	for(int i=0;i<N;i++){
		 count+=3-cou(A.at(i),B.at(i),C.at(i));
	}
	cout <<count<<endl;
	
}
	