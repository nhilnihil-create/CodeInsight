#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
	int a, num[4]={};
	for(int i = 0; i < 6; ++i){
		cin>>a;
		num[a-1]++;
	}
	int cnt=0;
	for(int i=0; i<4; i++){
		if(num[i]%2==1){
			cnt++;
		}
	}
    if(cnt==0||cnt==2){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}