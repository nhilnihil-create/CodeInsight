#include<bits/stdc++.h>
using namespace std;
const int N=40005;
int n,i,j,x=2,y=3;
vector<int>ans;
inline void addx(){
	ans.push_back(x);
	ans.push_back(x+2);
	if(n!=19994 || (x!=2))ans.push_back(x+4);
	x+=6;
}
inline void addy(){
	ans.push_back(y);
	ans.push_back(y+6);y+=12;
}
int main(){
//	ios::sync_with_stdio(0);
	cin>>n;
	if(n==3){
		puts("2 5 63");
		return 0;
	}
	if(n==4){
		puts("2 5 20 63");
		return 0;
	}
	if(n==6){
		puts("2 4 3 9 15 21");
		return 0;
	}
	n-=5;
	addx();addy();
	for(i=0;i<5000;++i)
		if((n-i*3)%2==0 && (n-i*3)/2<2500)break;
	if(i==5000)i--;
	for(j=1;j<=i;++j){
		addx();
	}
	int en=(n-i*3)/2;
	if(n==19994)en=2499;
	for(j=1;j<=en;++j)
		addy();
//	for(i=n;i;i-=pre[i])if(pre[i]==3)addx();else addy();
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
//	assert(ans.size()==n+5);
	for(vector<int>::iterator it=ans.begin();it!=ans.end();++it)
		cout<<*it<<' ';
	return 0;
}