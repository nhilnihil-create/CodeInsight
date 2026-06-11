#include<bits/stdc++.h>
using namespace std;

int n,a,b,p,problemone,problemtwo,problemthree;

int main(){
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++){
		cin>>p;
		if(p <= a){
			problemone++;
		}else if(p <= b){
			problemtwo++;
		}else{
			problemthree++;
		}
	}
	cout<<min(min(problemone,problemtwo),problemthree)<<endl;
}
