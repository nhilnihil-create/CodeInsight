#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#define int long long
const int inf=1145141919;
const int mod=1000000007;
using namespace std;
template<class T>void debug(T *a,int l,int r,const char *name){
	for(int i=l;i<r;i++)
		cout<<name<<"["<<i<<"]="<<a[i]<<endl;
}
int N;
int p[200001];
unordered_map<int,int> ma;
signed main(){
	int i,j;
	string s;
	cin>>s;
	N=s.size();
	for(i=0;i<N;i++)
		p[i+1]=p[i]^(1ll<<(s[i]-'a'));
	if(p[N]==0){
		cout<<1<<endl;
		return 0;
	}
	ma[p[N]]=0;
	for(i=N;i>0;i--)
		for(j=0;j<26;j++){
			auto it=ma.find(p[i]^(1ll<<j));
			if(it!=end(ma))
				it->second=min(it->second,ma[p[i]]+1);
			else
				ma[p[i]^(1ll<<j)]=ma[p[i]]+1;
		}
	cout<<ma[0]<<endl;
}