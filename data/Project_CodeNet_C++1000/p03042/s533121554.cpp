#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define pb push_back
int main(){
	string s;
	cin>>s;
	string f,l;
	f=s.substr(0,2);
	l=s.substr(2,2);
	int fo=stoi(f),la=stoi(l);
	bool a=fo>12||fo==0,b=la>12||la==0;
	if(a&&b){
		cout<<"NA"<<endl;
	}else if(a){
		cout<<"YYMM"<<endl;
	}else if(b){
		cout<<"MMYY"<<endl;
	}else{
		cout<<"AMBIGUOUS"<<endl;
	}
}
