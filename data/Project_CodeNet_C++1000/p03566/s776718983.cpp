#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	
	
	int N;
	cin>>N;
	
	vector<int> t,v;
	
	int sum = 0;
	
	
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		a*=2;
		//if(i==N-1)a--;
		t.push_back(a);

	}
	
	for(int i=0;i<N;i++){
		int b;
		cin>>b;
		b*=2;
		v.push_back(b);
	}
	
	t.push_back(1);
	v.push_back(0);
	
	vector<int> V;
	vector<int> maxi_V;
	
	for(int i=0;i<t.size();i++){
		for(int j=0;j<t[i];j++){
			V.push_back(0);
			if(j!=0||i==0)maxi_V.push_back(v[i]);
			else maxi_V.push_back(min(v[i],v[i-1]));
		}
	}
	
	
	for(int i=1;i<V.size();i++){
		V[i] = min(V[i-1] + 1,maxi_V[i]);
		
		int k = i;
		
		while(true){
			if(abs(V[k]-V[k-1])<=1)break;
			V[k-1] = V[k]+1;
			k--;
		}
	}
	
	double ans = 0.0;
	
	for(int i=1;i<V.size();i++){
		ans += ((double)V[i]+V[i-1])/2.0;
	}
	/*
	for(int i=0;i<V.size();i++){
		cout<<i<<':'<<V[i]<<endl;
	}
	*/
	
	cout<<fixed<<setprecision(15)<<ans/4.0<<endl;
		
			
	
	
	return 0;
}
