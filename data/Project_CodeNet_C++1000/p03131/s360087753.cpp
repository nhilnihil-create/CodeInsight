#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;
ll N;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m;
int ans=0;

vector<vector<int>> grid;
vector<ll> H, S;
vector<bool> seen;
vector<ll>sum;
vector<int> pl;

vector<int> uf;

int main(int argc, char **argv){
	ll k,a,b;cin>>k>>a>>b;
	ll bis=1;
	ll yen=0;
	if(a+2>=b){
		cout<<bis+k<<endl;
		return 0;
	}else{
		if(max(0LL,a-bis)+2LL<=k){
			k-=(max(0LL,a-bis)+2LL);
			bis=b;
		}else{
				bis+=k;
				cout<<bis<<endl;
				k=0;
				return 0;
		}

		ll ex=k/2;
		ll ama=k%2;
		bis+=(b-a)*ex + ama;
		cout<<bis<<endl;
		/*
		while(k>=1){
			//cout<<(max(0LL,a-bis)+2LL)<<endl;
			if((max(0LL,a-bis)+2LL)<=k){
				k-=(max(0LL,a-bis)+2LL);
				bis=bis+max(0LL,a-bis)-a+b;
			}else{
				bis+=k;
				cout<<bis<<endl;
				k=0;
				return 0;
			}
		}*/
	}
}
