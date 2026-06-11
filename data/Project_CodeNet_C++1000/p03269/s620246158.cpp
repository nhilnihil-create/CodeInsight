#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long
int L;
typedef std::pair<int,int> pii;
std::vector<pii> e[25];
int main(){
	std::cin>>L;
	int lg=0,tmp=L;
	while(tmp) tmp>>=1,++lg;
	int cnt=0;
	rep(i,1,lg-1){
		e[i].emplace_back(i+1,0);
		e[i].emplace_back(i+1,1<<lg-i-1);
		cnt+=2;
	}
	tmp=1<<lg-1;
	_rep(i,lg-1,1){
		if(L>>(i-1)&1){
			e[1].emplace_back(lg-i+1,tmp);
			tmp+=1<<i-1,++cnt;
		}
	}
	std::cout<<lg<<' '<<cnt<<'\n';
	rep(i,1,lg){
		for(pii it:e[i])
			std::cout<<i<<' '<<it.first<<' '<<it.second<<'\n';
	}
	return 0;
}