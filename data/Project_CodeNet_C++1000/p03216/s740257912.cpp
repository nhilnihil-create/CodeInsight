#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

void solve(string &S,int k){
	long long D=0,M=0,DM=0,ans=0;
	for(int i=0;i<S.size();i++){
		if(i-k>=0){
			if(S[i-k]=='M'){
				M--;
			}
			if(S[i-k]=='D'){
				D--;
				DM -= M;
			}
		}
		
		if(S[i]=='D')D++;
		if(S[i]=='M'){
			M++;
			DM += D;
		}
		if(S[i]=='C'){
			ans += DM;
		}
	}
	
	cout<<ans<<endl;
}


int main(){
	
	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		int k;
		cin>>k;
		solve(S,k);
	}
	
    return 0;
}
