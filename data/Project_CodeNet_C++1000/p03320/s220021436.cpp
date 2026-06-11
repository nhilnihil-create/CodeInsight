#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;
	for(ll i=0;i<9 && n>0;i++,n--){
		cout<<i+1<<endl;
	}
	for(ll i=0;i<9 && n>0;i++,n--){
		cout<<(i+1) * 10 + 9<<endl;
	}
	ll cnt=1;
	long long t = 99; 
	long long diff=100;
	while(n>0){
		//for(ll i=cnt;i<((cnt+1)*10) - 9*(cnt/10) && n>0;i++,n--){
		if (cnt<10)
		for(ll i=0;i<(cnt*9 + 10) && n>0;i++,n--){
			t+=diff;
			cout<<t<<endl;
		}
		else
		for(ll i=0;i<(cnt*10 - 10) && n>0;i++,n--){
			t+=diff;
			cout<<t<<endl;
		}
		//cout<<cnt<<"-----\n";
		cnt++;
		diff*=10;
	}
}
