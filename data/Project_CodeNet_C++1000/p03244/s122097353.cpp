# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> v(n);	
	map<int,int> impares;
	map<int,int> pares;
	for(int i = 0; i< n; i++){
		cin >>v[i];		
	}
	for(int i = 0; i< n; i+=2){
		pares[v[i]]++;
	}
	for(int i = 1; i< n; i+=2){
		impares[v[i]]++;
	}
	int ma = -1;
	int ma2 = -1;
	int mp,mi; 
	for(auto p: pares){		
		if(ma<=p.second){
			ma = max(ma,p.second);
			mp = p.first;
		}
	}
	for(auto p: impares){
		if(ma2 <= p.second){
			ma2 = max(ma2,p.second);
			mi = p.first;
		}
	}
	int ama = -1;
	int ama2 = -1;
	pares[mp] = -1;
	impares[mi] = -1;
	for(auto p: pares){
		ama = max(ama,p.second);
	}
	for(auto p: impares){
		ama2 = max(ama2,p.second);
	}
	
	if(n-ma2-ma == 0 && v[0] == v[1]) 
		cout<<ma2<<'\n';
	else if(mi == mp){
		if(ma2<ma){
			cout<< n-ma-ama2<<'\n';
		}
		else if(ma2>ma){
			cout<< n-ma2-ama<<'\n'; 
		}
		else{
			int a = max(ama,ama2);
			cout<<n-ma-a<<'\n';
		}
	}
	else cout<<n-ma2-ma<<'\n';
}
