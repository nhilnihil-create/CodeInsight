#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	int k; cin>>k;
	int cnt=0;
	for(int i=1; i<=k; i++){
		if(i%2==0){ //Even
			for(int j=i+1; j<=k; j++){
				if(j%2!=0) cnt++;
			}
		} else {
			for(int j=i+1; j<=k; j++){
				if(j%2==0) cnt++;
			}
		}
	}
	cout << cnt << endl;	
}