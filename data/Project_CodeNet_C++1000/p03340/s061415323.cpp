#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,s,j,tmp,sum;
long long ans;
int a[N];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		sum-=a[i-1];
		tmp=tmp^a[i-1];
		while(j+1<=n&&tmp^a[j+1]==sum+a[j+1]){
			sum+=a[++j];
			tmp=tmp^a[j];
			if (sum!=tmp){
				sum-=a[j];
				tmp=tmp^a[j];
				j--;
				break;
			}
		}	
		ans+=j-i+1;
	}
	cout<<ans;
	return 0;
}