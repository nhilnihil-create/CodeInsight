#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	int n;
	string w[105];
	char e;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i];
		if(i!=0 && w[i][0]!=e){
			cout<<"No"<<endl;
			return(0);
		}
		e=w[i][w[i].size()-1];
	}
	sort(w,w+n);
	for(int i=0;i<n-1;i++){
		if(w[i]==w[i+1]){
			cout<<"No"<<endl;
			return(0);
		}
	}
	cout<<"Yes"<<endl;
	return(0);
}