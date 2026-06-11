#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int N,A,B;
	cin>>N>>A>>B;
	
	int n = N;
	
	vector<int> num(A,1);
	n-=A;
	num[0] = B;
	n-=B-1;
	
	if(n<0){
		cout<<-1<<endl;
		return 0;
	}
	
	for(int i=1;i<num.size();i++){
		num[i] += min(n,B-1);
		n -= min(n,B-1);
	}
	
	if(n!=0){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> ans(N);
	for(int i=0;i<N;i++)ans[i] = i+1;
	int sum = 0;
	
	for(int i=0;i<num.size();i++){
		reverse(ans.begin()+sum,ans.begin()+sum+num[i]);
		sum+=num[i];
	}
	
	for(int i=0;i<N;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}