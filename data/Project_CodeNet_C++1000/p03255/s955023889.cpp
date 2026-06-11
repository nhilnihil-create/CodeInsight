#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	// your code goes here
	vector<long long int> vec,sums;
	long long int sum=0;
	long long int ans=0;
	long long int n,x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		long long int a;
		cin>>a;
		vec.push_back(a);
		sum+=a;
		sums.push_back(sum);
	}
	reverse(vec.begin(),vec.end());
	reverse(sums.begin(),sums.end());
	sums.push_back(0);
	ans=sum*5+x*2*n;
	if(n==1){
		cout<<ans<<"\n";
	}else if(n==2){
		cout<<sum*5+x*3;
	}else{
		for(int i=1;i<n;i++){
			long long int top=(sums[0]-sums[i])*5+x*i+x*n;
			long long int t2=5;
			for(int j=i;j<n;j+=i){
				if(j+i<n){
					top+=(sums[j]-sums[j+i])*t2;
				}else{
					top+=(sums[j])*t2;
				}
				t2+=2;
				//cout<<top<<" ";
				if(top>ans)break;
			}
			
			if(top<ans)ans=top;
		}
		cout<<ans<<"\n";
	}
	return 0;
}