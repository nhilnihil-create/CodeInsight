#include <bits/stdc++.h>
using namespace std;
long long po[35];
int sign[35];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long sum=1;
	po[0]=1;
	for(int i=1;i<35;i++){
		po[i]=po[i-1]*2;
		sum+=po[i];
	}
	int n;
	cin>>n;
	vector<pair<long long, long long>>v;
	for(int i=0;i<n;i++){
		long long x, y;
		cin>>x>>y;
		v.push_back({x, y});
		if(i>0 && (v[i-1].first+v[i-1].second+x+y)%2!=0){
			//cout<<"YEET\n";
			cout<<-1;
			return 0;
		}
	}
	string s="";
	if((v[0].first+v[0].second)%2==0){
		s="R";
		for(int i=0;i<n;i++){
			v[i].first--;
		}
		cout<<36<<"\n";
		cout<<1<<" ";
		for(int i=0;i<35;i++) cout<<po[i]<<" ";
			cout<<"\n";
	}
	else{
		cout<<35<<"\n";
		for(int i=0;i<35;i++) cout<<po[i]<<" ";
			cout<<"\n";
	}
	for(int i=0;i<n;i++){
		string t=s;
		long long x=v[i].first, y=v[i].second;
		long long minus=(sum-x-y)/2;
		//cout<<x<<" "<<y<<endl;
		for(int i=0;i<35;i++){
			if((1ll<<i)&minus){
				sign[i]=-1;
			}
			else sign[i]=1;
		}
		for(int i=0;i<35;i++){
			if(x%(1ll<<(i+1))!=0){
				if(sign[i]==-1) t.push_back('L');
				else t.push_back('R');
				x-=sign[i]*(1ll<<i);
			}
			else{
				if(sign[i]==1) t.push_back('U');
				else t.push_back('D');
			}
		}
		cout<<t<<"\n";
	}
}