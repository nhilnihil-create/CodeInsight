#include <bits/stdc++.h>

#define int long long 
#define MOD 1000000007



using namespace std;


signed main(){

	int N,P;
	cin>> N>>P;
	
	unordered_map<int,int> sosu;

	int q = (int)sqrt(P)+1;
	
	if(N==1){
		cout << P <<endl;
		return 0;
	}
	int ans = 1;
	

	for(int i=2;i<=q;i++){
		int k=0;		
		while(1){
			if(P%i==0){
				P=P/i;
				k++;	
			}
			else{
				break;
			}	
		}
		
		if(k>=N){
			int y = (int)k/N;
			for(int j=0;j<y;j++){
				ans = ans*i;
			}
		}
		
		if(i>P){
			break;
		}
		
	}
	
	cout << ans << endl;
 	
 	return 0;
	

}