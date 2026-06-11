#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define MOD (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;

int h,w;
char board[410][410];
bool board1[410][410];

bool check1(int i, int j) {
	return (i >= 0) && (i < h) && (j >= 0) && (j < w) && (!board1[i][j])&&(board[i][j]=='#');
}

bool check2(int i, int j) {
	return (i >= 0) && (i < h) && (j >= 0) && (j < w) && (!board1[i][j])&&(board[i][j]=='.');
}

int main(void){
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n),x;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		ll sum=0;
		for(ll j=i;j<n;j++){
			sum+=a[j];
			x.push_back(sum);
		}
	}
	ll digit=0,sum=0;
	for(ll i=39;i>=0;i--){
		digit=(1LL<<i);
		ll cnt=0;
		for(ll j=0;j<x.size();j++){
			if(((sum+digit)&x[j])==sum+digit)cnt++;
		}
		if(cnt>=k)sum+=digit;
	}
	cout<<sum<<endl;
    return 0;
}