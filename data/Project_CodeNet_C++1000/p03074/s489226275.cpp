#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,k;
	string s;
	cin>>n>>k>>s;
	vector<pair<long long,long long>> line;

	int now;
	int cnt=0;
	for(int i=0;i<n;i++){
		int hoge=s.at(i)-'0';

		if(i==0){
			now=hoge;
			cnt++;
			continue;
		}

		if(now!=hoge){
			line.push_back(make_pair(now,cnt));
			cnt=1;
			now=hoge;
		}else{
			cnt++;
		}
	}
	line.push_back(make_pair(now,cnt));

	long long zero=0;
	vector<long long> Z;

	for(int i=0;i<(int)line.size();i++){
		if(line.at(i).first==0){
			zero++;
			Z.push_back(i);
		}
	}

	if(zero<=k){
		cout<<n<<endl;
		return 0;
	}

	long long ans=0;
	for(int i=0;i<k;i++){
		int pos=Z.at(i);

		if(i==0){
			if(pos>0){
				ans+=line.at(pos-1).second;
			}
		}

		ans+=line.at(pos).second;
		if(pos<(int)line.size()-1){
			ans+=line.at(pos+1).second;
		}
	}

	long long pre=ans;

	for(int i=k;i<(int)Z.size();i++){
		int r=Z.at(i);
		int l=Z.at(i-k);

		pre-=line.at(l).second;
		if(l>0) pre-=line.at(l-1).second;

		pre+=line.at(r).second;
		if(r<(int)line.size()-1) pre+=line.at(r+1).second;

		ans=max(ans,pre);
	}

	cout<<ans<<endl;

	return 0;
}
