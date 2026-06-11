#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
using namespace std;
vector<int> v[5003];
int main(){
	int n; cin>>n;
	rep(k,1,5000)
		if (k*(k-1)/2==n){
			cout<<"Yes"<<endl<<k<<endl;
			int c=0;
			rep(i,1,k)
				rep(j,i+1,k){
					v[i].push_back(++c);
					v[j].push_back(c);
				}
			rep(i,1,k){
				printf("%d ",v[i].size());
				rep(j,0,(int)v[i].size()-1)
					printf("%d ",v[i][j]);
				putchar('\n');
			}
			return 0;
		}
	cout<<"No"<<endl;
	return 0;
} 