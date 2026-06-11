#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N+1,0);
	for(int i=1;i<=N;i++)cin>>A[i];
	
	int ok = 200001;
	int ng = 0;
	
	while(ok-ng>1){
		int mid = (ok+ng)/2;
		bool f = true;
		vector<pair<int,int>> now;
		for(int i=1;i<A.size();i++){
			if(A[i]>A[i-1]){
				now.emplace_back(0,A[i]-A[i-1]);
			}
			else{
				int t = A[i-1]-A[i];
				while(t!=0){
					if(now.back().second>t){
						now.back().second-=t;
						t=0;
						break;
					}
					else{
						t -= now.back().second;
						now.pop_back();
					}
				}
					
				long long S = 0;
				while(now.size()!=0&&now.back().first==mid-1){
					S += now.back().second;
					now.pop_back();
				}
				if(now.size()==0){
					f = false;
					break;
				}
				if(now.back().second!=1){
					now.back().second--;
					now.emplace_back(now.back().first,1);
				}
				now.back().first++;
				if(S!=0)now.emplace_back(0,S);
			
			
			}
			
		}
		
		
		
		
		if(f)ok = mid;
		else ng = mid;
	}
	
	cout<<ok<<endl;
	
	return 0;
}