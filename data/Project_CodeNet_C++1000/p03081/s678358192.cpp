#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

#define L 0
#define R 1

lli n,q;
string s;

bool calc(lli pos,vector<pair<char,char>> *v,bool dir){
	lli goal;
	lli now = pos;
	if(dir==L)goal=-1;
	else goal=n;

	for(lli i=0;i<q;i++){
		if(now<0 || now>=n)break;
		if(v->at(i).first == s[now]){
			if(v->at(i).second=='L')now--;
			else now++;
		}
	}
	if(now==goal)return true;
	else return false;
}

lli func(vector<pair<char,char>> *v){
	/*まず左から落ちるものを探し出す*/
	lli high=n;
	lli low=-1;
	lli middle;
	while(high-low>1){
		middle = (low+high)/2;
		if(calc(middle,v,L)){
			low = middle;
		}
		else high = middle;
	}
	lli left = high;

	high=n;
	low =-1;
	while(high-low>1){
		middle = (low+high)/2;
		if(calc(middle,v,R)){
			high=middle;
		}
		else low = middle;
	}
	lli right = low;
	if(DEBUG)cout<<"left="<<left<<" right="<<right<<endl;
	return right-left+1;
}

signed main(){

	cin>>n>>q;
	cin>>s;

	vector<pair<char,char>> v;
	REP(i,0,q){
		char t,d;
		cin>>t>>d;
		v.push_back(make_pair(t,d));
	}

	/*2分探索で左から落ちるゴーレムと右から落ちるゴーレムの2つを見つけ出す。*/
	cout<<func(&v)<<endl;

	return 0;
}