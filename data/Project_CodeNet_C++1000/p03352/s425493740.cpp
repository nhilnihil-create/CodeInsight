#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int x,ans=1;
	cin>>x;
	for(int i=1;i<=x;i++){
		for(int j=2;j<=i;j++){
			int k=i,cnt=0;
			while(k%j==0)cnt++,k/=j;
			if(k==1 && cnt>1){
				ans=i;
			}
		}
	}
	cout<<ans;
}



