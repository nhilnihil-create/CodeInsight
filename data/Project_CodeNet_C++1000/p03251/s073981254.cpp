#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define x first
#define y second
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'


int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<int> v(n),vv(m);
	for(auto &x:v)cin>>x;
	for(auto &x:vv)cin>>x;
	for(int z=x+1;z<=y;z++){
		bool f=1;
		for(auto x:v){
			if(x>=z){
				f=0;
				break;
			}
		}
		for(auto x:vv){
			if(x<z){
				f=0;
				break;
			}
		}
		if(f){
			printf("No War\n");
			return 0;
		}
	}
	printf("War\n");
	return 0;
}