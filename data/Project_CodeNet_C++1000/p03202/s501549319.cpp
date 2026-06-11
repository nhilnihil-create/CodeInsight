#include<bits/stdc++.h>
using namespace std;
int a[200003],n;
vector<pair<int,int> >built;
void in(int x,int num){
	if(!built.empty()&&x==built.back().first)built.back().second+=num;
	else built.push_back(make_pair(x,num)); 
}
int l(){
	int cnt=0;
	for(int i=0;i<built.size();i++)cnt+=built[i].second;
	return cnt; 
} 
bool check(int num){
	built.clear();
	for(int i=0;i<n;i++){
		int cur=l();
		if(cur<a[i])
			in(0,a[i]-cur);
		else{
			while(cur-built.back().second>=a[i])cur-=built.back().second,built.pop_back();
			built.back().second=a[i]-(cur-built.back().second);
			while(!built.empty()&&built.back().first==num-1)built.pop_back();
			if(built.empty())return 0;
			int en=built.back().first+1;
			built.back().second--;
			if(built.back().second==0)built.pop_back();
			in(en,1);
			in(0,a[i]-l());
		}
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int l=0,r=n;
	while(r>l+1){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<r;
}