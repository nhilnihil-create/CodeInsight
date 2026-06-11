#include<iostream>
#include<string>
#include<vector>
#define push push_back
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}

int min(int a,int b){
	return (a<b)?a:b;
}

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> vec;
	int now=1,tmp=0;
	rep(i,s.size()){
		if(s[i]==(char)(now+'0'))tmp++;
		else{
			now=1-now;
			vec.push(tmp);
			tmp=1;
		}
	}
	if(tmp!=0)vec.push(tmp);
	if(vec.size()%2==0)vec.push(0);
	int ans=0;
	tmp=0;
	int left=0,right=0;
	for(int i=0;i<vec.size();i+=2){
		int nextleft=i,nextright=min(i+2*k+1,vec.size());
		while(left<nextleft){
			tmp-=vec[left];
			left++;
		}
		while(right<nextright){
			tmp+=vec[right];
			right++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}