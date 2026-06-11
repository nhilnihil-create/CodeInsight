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
	int s,k=0;
	cin>>s;
	vector<int> v;
	v.push_back(s);
	map<int,int> mp;
	mp[s]=1;
	while(1){
		if(v[k]%2==0){
			v.push_back(v[k]/2);
			k++;
		}
		else{
			v.push_back((3*v[k])+1);
			k++;
		}
		if(mp[v[k]]!=0){
			break;
		}
		else{
			mp[v[k]]=1;
		}
	}
	cout<<(k+1);
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
