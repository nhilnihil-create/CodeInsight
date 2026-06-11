#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

/*店iとjoisinoの店が、いくつの同じ時間帯で営業しているかを調べる(dfs)*/
//時間帯の数は10以下なので全探索(0 1 0 0 0 1 0 0 0 0 のように営業するなら1　　しないなら0　として全パターン試す)

vector<vector<ll>> f;//店がある時刻に営業しているか
vector<vector<ll>> p;//利益

ll n,output=-INF;

void dfs(ll time,bool OPEN,vector<bool> &open){//time:何番目の時間帯まで調べたか　OPEN:timeの時間帯に開いているか　
	if(time==10){
		bool all_close=true;//joisinoの店が全て閉まっていることは許されない
		for(ll i=0;i<10;i++){
			if(open[i]!=false){all_close=false;break;}
		}
		if(all_close){return;}


		ll answer=0;
		for(ll i=0;i<n;i++){//店iについて
			ll how_many_one=0;//共通の時刻は何個か
			for(ll j=0;j<10;j++){
				if(f[i][j] && open[j]){how_many_one++;}
			}
			answer+=p[i][how_many_one];
		}
		output=max(output,answer);

		return;
	}

	if(OPEN){open[time]=true;}
	else{open[time]=false;}

	dfs(time+1,true,open);
	dfs(time+1,false,open);

	return;
}

int main(){
	cin>>n;
	f.assign(n,vector<ll>(10,0));//n個の店について、10個の時間帯に対し、開いているか
	p.assign(n,vector<ll>(11,0));//n個の店について、joisinoと同じ時間帯の個数に対する、利益

	for(ll i=0;i<n;i++){
		for(ll j=0;j<10;j++){
			cin>>f[i][j];
		}
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<=10;j++){
			cin>>p[i][j];
		}
	}

	vector<bool> open(10,false);
	dfs(0,true,open);
	dfs(0,false,open);


	cout<<output<<endl;

	return 0;
}