#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 12345678912356
#define MAX_V 200100


vector<int> G[MAX_V];
int f[MAX_V];
int temp[MAX_V];
int N, M;
string s;

bool foo(int x){
	// cout<<x<<" "<<f[x]<<" "<<s[x]<<endl;
	
	 if(f[x] == 2) return false;
	
	f[x] = 1;
	
	
	
	for(int y : G[x]){
		// cout<<y<<endl;
		// if(y == x) continue;
		if(s[y] == s[x]){
			if(f[y] == 2)continue;
			// f[y] = 1;
			for(int z : G[y]){
				// if(z == x)continue;
				if(f[z] == 2)continue;
				if(s[y] == s[z])continue;
				else {
					if(f[z] == 1) return true;
					if(foo(z)) return true;
				}
			}
			// f[y] = 2;
		}
	}
	 f[x] = 2;
	return false;
}


signed main(){
	int A, B;
	bool fl = false;

	
	cin>>N>>M;
	cin>>s;
	
	rep(i, M){
		cin>>A>>B;A--,B--;
		G[A].push_back(B);
		G[B].push_back(A);
		// if(A==B)temp[A] = true;
	}
	
	rep(i, N){
		 // cout<<i<<" -----"<<endl;
		if(foo(i)){
			fl = true;
			// cout<<"ture"<<endl;
			break;
		}
	}
	// rep(i, N)
		// cout<<"f "<<i<<" "<<f[i]<<endl;
	
	cout<<(fl?"Yes":"No")<<endl;
	
	
	return 0;
}