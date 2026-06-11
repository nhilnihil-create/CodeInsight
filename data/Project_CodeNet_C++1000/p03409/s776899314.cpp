#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > p(2*n);
	map<int,bool> s;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		s[p[i].first]=1;
	}
	for(int i=n;i<2*n;i++)
	cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end());
	set<int> t;
	int m=0;
	for(int i=0;i<2*n;i++){
		if(s[p[i].first])
		t.insert(p[i].second);
		else{
			int f=-1;
			for(int x : t){
				if(p[i].second>x)
				f=x;
				else
				break;
			}
			if(f!=-1){
				t.erase(f);
				m++;
			}
		}
	}
	cout<<m;
} 