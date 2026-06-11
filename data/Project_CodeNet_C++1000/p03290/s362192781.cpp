#include<bits/stdc++.h>
using namespace std;
int main(){
	int d,g,ans=100000000;
	cin>>d>>g;
	vector<int>p(d),c(d);
	for(int i=0;i<d;i++)cin>>p.at(i)>>c.at(i);
	for(int i=0;i<(1<<d);i++){
		vector<int>a(p);
		int s=0,t=0;
		for(int j=0;j<d;j++){
			if(i&(1<<j)){
				s+=(j+1)*a.at(j)*100;
				s=s+c.at(j);
				t+=a.at(j);
				a.at(j)=0;
			}
		}
		int k=d-1;
		while(k>=0&&a.at(k)==0)k--;
		while(k>=0&&a.at(k)>0&&s<g){
			s+=(k+1)*100;
			a.at(k)--;
			t++;
		}
		if(s>=g) ans=min(ans,t);
	}
	cout<<ans;
}