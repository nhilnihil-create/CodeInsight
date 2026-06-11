#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> ball(n);
	map<int,int> maps;

	for(int i=0;i<n;i++){
		cin>>ball.at(i);
		if(maps.count(ball.at(i))) maps.at(ball.at(i))++;
		else maps[ball.at(i)]=1;
	}

	vector<int> num;

	for(auto a:ball){
		if(maps.at(a)!=0){
			num.push_back(maps.at(a));
			maps.at(a)=0;
		}
	}

	sort(num.begin(),num.end());

	long long ans=0;

	int cnt=0;

	for(int i=num.size()-1;i>=0;i--){
		if(cnt>=k) break;
		cnt++;

		ans+=num.at(i);
	}

	cout<<n-ans<<endl;

	return 0;
}
