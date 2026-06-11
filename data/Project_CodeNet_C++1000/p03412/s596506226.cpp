#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1100000000

int main(){
	
	int N;
	cin>>N;
	
	vector<int> a(N),b(N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	
	int ans = 0;
	
	for(int i=28;i>=0;i--){
		sort(b.begin(),b.end());
		
		int l[2] = {1<<i,(1<<(i+1))+(1<<i)};
		int r[2] = {1<<(i+1),1<<(i+2)};
		int t = 0;
		for(int j=0;j<N;j++){
			for(int k=0;k<2;k++){
				int d = distance(lower_bound(b.begin(),b.end(),l[k]-a[j]),lower_bound(b.begin(),b.end(),r[k]-a[j]));
				t ^= (d&1);
			}
		}

		ans ^= t<<i;
		
		for(int j=0;j<N;j++){
			if((a[j]>>i)&1)a[j]^=(1<<i);
			if((b[j]>>i)&1)b[j]^=(1<<i);
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}