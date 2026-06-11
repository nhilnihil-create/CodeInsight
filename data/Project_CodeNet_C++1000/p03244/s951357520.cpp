#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define cool ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define MAX 1000001
#define mod 1000000007
#define pie 3.14159265358979323846
void solve()
{
	int n,i,mini1=MAX,mini2=MAX,j;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)
	cin>>a[i];
	map<int,int> mp1;
	map<int,int> mp2;
	map<int,int> mp3;
	vector< pair<int,int> > v1;
	vector< pair<int,int> > v2;
	for(i=1;i<=n;i++){
		if(i%2!=0)
		mp1[a[i]]++;
		else
		mp2[a[i]]++;
	}
	for(i=1;i<=100000;i++){
		if(mp1[i]!=0)
		v1.push_back(make_pair(mp1[i],i));
		if(mp2[i]!=0)
		v2.push_back(make_pair(mp2[i],i));
	}
	sort(v1.begin(),v1.end(),greater< pair<int,int> >());
	sort(v2.begin(),v2.end(),greater< pair<int,int> >());
	for(i=0;i<v1.size();i++){
		int ans=0,k,f=0;
		ans+=(n/2)-v1[i].first;
		k=v1[i].second;
		for(j=0;j<v2.size();j++){
			if(v2[j].second!=k){
				ans+=(n/2)-v2[j].first;
				f=1;
				break;
			}
		}
		if(f==1)
		mini1=min(mini1,ans);
		else{
			ans+=(n/2);
			mini1=min(mini1,ans);
		}
	}
	for(i=0;i<v2.size();i++){
		int ans=0,k,f=0;
		ans+=(n/2)-v2[i].first;
		k=v2[i].second;
		for(j=0;j<v1.size();j++){
			if(v1[j].second!=k){
				ans+=(n/2)-v1[j].first;
				f=1;
				break;
			}
		}
		if(f==1)
		mini1=min(mini1,ans);
		else{
			ans+=(n/2);
			mini1=min(mini1,ans);
		}
	}
	cout<<min(mini1,mini2);
}
int main()
{ 
    cool;
    int t;
    //cin>>t;
    t=1;
    while(t--){
    	solve();
	}
    return 0;
}
