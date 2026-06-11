#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n, a[N];
vector <pair<int,int> > v;
vector <pair<int,int> >::iterator it;
inline bool check(int k){
	v.clear();
	for(int i=1; i<=n; ++i){
		if(a[i]>a[i-1])v.insert(v.end(),make_pair(1,a[i]-a[i-1]));
		else if(a[i]<a[i-1]){
			int x=0,j; it=v.begin();
			for(j=0; j<v.size(); ++j, ++it){
				x+=v[j].second;
				if(x>=a[i]){
					v[j].second-=x-a[i];
					break;
				}
			}
			++it; if(it!=v.end())v.erase(it,v.end()); --it;
			for(j=v.size()-1; ~j; --j,--it){
				if(v[j].first==k)v[j].first=1;
				else{
					int tmp=v[j].first;
					if(v[j].second>1)v[j].second--,++it; else v.erase(it);
					v.insert(it,make_pair(tmp+1,1)); break;
				}
			}
			if(j==-1)return 0;
		}else{
			int j=v.size()-1; it=--v.end();
			for(; ~j; --j,--it){
				if(v[j].first==k)v[j].first=1;
				else{
					int tmp=v[j].first;
					if(v[j].second>1)v[j].second--,++it; else v.erase(it);
					v.insert(it,make_pair(tmp+1,1)); break;
				}
			}
			if(j==-1)return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n); for(int i=1; i<=n; ++i)scanf("%d",&a[i]);
	int l=1, r=n, tmp=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))tmp=r=mid;
		else l=mid+1;
	}
	printf("%d", tmp);
	return 0;
}