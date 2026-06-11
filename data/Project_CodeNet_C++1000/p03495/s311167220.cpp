    #include<bits/stdc++.h>
    using namespace std;
    int main(){
		int n,k,a,ans=0,b[200005]={};
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a;
			b[a]++;
		}
		sort(b,b+200001);
		for(int i=0;i<200001-k;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
      return(0);
	}