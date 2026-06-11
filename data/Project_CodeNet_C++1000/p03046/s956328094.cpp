#include<bits/stdc++.h>
//#include<iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 2000006;
 
int m,k;

vector<int> v[22];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>m>>k;
	
	if( k >= (1<<m) ){
		cout<<-1;
		return 0;
	}
	if( m == 1 ){
		if(k == 0){
			cout<<"0 0 1 1";
		}else{
			cout<<-1;
		}
		return 0;
	}
	
	if(m == 0){
		cout<<"0 0";
		return 0;
	}
	
	v[1].push_back(0);
	v[1].push_back(1);
	v[1].push_back(2);
	v[1].push_back(3);
	
	int idx = 1;
	
	for(int i=2;i<m;i++){
		for(int j=(1<<i);j<(1<<(i+1));j++){
			v[i].push_back(j);
			if(j == k) idx = i;
		}
	}
	
	for(int i=1;i<m;i++){
		if(i == idx)continue;
		for(int x:v[i]){
			cout<<x<<" ";
		}
	}
	cout<<k<<" ";
	for(int i=m-1;i>0;i--){
		if(i == idx)continue;
		reverse(v[i].begin(),v[i].end());
		for(int x:v[i]){
			cout<<x<<" ";
		}
	}
	
	for(int x:v[idx]){
		if(x == k)continue;
		cout<<x<<" ";
	}
	
	cout<<k<<" ";
	
	reverse(v[idx].begin(),v[idx].end());
	
	for(int x:v[idx]){
		if(x == k)continue;
		cout<<x<<" ";
	}
	
	return 0;
}
