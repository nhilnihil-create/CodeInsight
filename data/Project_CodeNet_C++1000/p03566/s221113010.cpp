#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=4e4+5;
 
 
 
int main(){
	int N;
	cin>>N;
	int t[101];
	int v[101];
	rep1(i,N)cin>>t[i];
	rep1(i,N)cin>>v[i];
	
	//0.5秒ごとの区間に分け、各点での制限速度をメモ、速度は2倍で転記
	vi lm;
	v[0]=0;
	rep1(i,N){
		lm.push_back(2*min(v[i],v[i-1]));
		rep(j,2*t[i]-1)lm.push_back(2*v[i]);
	}
	lm.push_back(0);
	//前から見た最大速度と、後ろから見た最大速度を見る
	int l=sz(lm);
	int a[MAX];
	rep(i,l)a[i]=1e9;
	rep(i,l){
		for(int j=i-200;j<=i+200;j++){
			if(0<=j && j<=l-1){
				a[i]=min(a[i],lm[j]+abs(j-i));
			}
		}
	}
	double ans=0;
	rep(i,l)ans+=a[i];
	ans/=4;
	cout<<fixed;
	cout<<setprecision(12)<<ans<<endl;
}