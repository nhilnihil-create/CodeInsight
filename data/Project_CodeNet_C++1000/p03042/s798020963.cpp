//#include<bits/stdc++.h>
#include<iostream>

using namespace std;

typedef long long ll;

const int N = 200005;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	
	int x = (s[0]-'0')*10 + (s[1]-'0');
	int y = (s[2]-'0')*10 + (s[3]-'0');
	
	if(x < 13 && x != 0){
		if(y < 13 && y != 0){
			cout<<"AMBIGUOUS";
		}
		else{
			cout<<"MMYY";
		}
	}else{
		if(y < 13 && y!=0){
			cout<<"YYMM";
		}
		else{
			cout<<"NA";
		}
	}
	
	return 0;
}
