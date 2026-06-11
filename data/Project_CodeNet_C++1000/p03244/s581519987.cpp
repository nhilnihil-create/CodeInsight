#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
signed main() 
{
    IOS;    
    int n;
    cin>>n;
    map<int,int>mp1;
    map<int,int>mp2;
    int maxc1=0;
    int maxc2=0;
    int maxi1=0;
    int maxi2=0;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	if(i%2){
    		mp1[x]++;
    		if(mp1[x]>maxc1){
    			maxc1=mp1[x];
    			maxi1=x;
    		}
    	}
    	else {
    		mp2[x]++;
    		if(mp2[x]>maxc2){
    			maxc2=mp2[x];
    			maxi2=x;
    		}
    	}
    }
    if(maxi1!=maxi2 ||maxc1!=maxc2){
    int ans=0;
    for(auto it=mp1.begin();it!=mp1.end();it++){
    	if(it->first!=maxi1)ans+=it->second;
    }
    for(auto it=mp2.begin();it!=mp2.end();it++){
		if(it->first!=maxi2)ans+=it->second;  
		  }
    if(ans!=0)cout<<ans;
    else{
    	if(*mp1.begin()==*mp2.begin())cout<<n/2;
    	else cout<<0;
    }
}
	else{
		vector<int>v1;
		vector<int>v2;
		 for(auto it=mp1.begin();it!=mp1.end();it++){
    	v1.push_back(it->second);
    }
     for(auto it=mp2.begin();it!=mp2.end();it++){
    	v2.push_back(it->second);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans1=0;
    int ans2=0;
    for(int i=0;i<v1.size();i++){
    	ans1+=v1[i];
    }
   if(v1.size()>=2) ans1-=v1[v1.size()-2];

    for(int i=0;i<v2.size();i++){
    	ans2+=v2[i];
    }
     if(v2.size()>=2)ans2-=v2[v2.size()-2];
    // cout<<v2.size()<<endl;
    cout<<min(ans1,ans2)+n/2-maxc1;
	}
    
    
    return 0; 
} 
