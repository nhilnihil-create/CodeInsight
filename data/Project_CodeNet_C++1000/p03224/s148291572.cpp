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
const int MAX=2e5+5;

int main(){
	int N;
	cin>>N;
	int k=-1;
	rep1(i,500){
		if((i*(i-1))/2==N)k=i;
	}
	if(k==-1)cout<<"No"<<endl;
	else{
      	cout<<"Yes"<<endl;
      	cout<<k<<endl;
		vi S[500];
		int ind=1;
		rep(i,k)rep(j,k)if(i<j){
			S[i].push_back(ind);
			S[j].push_back(ind);
			ind++;
		}
		rep(i,k){
			cout<<sz(S[i])<<" ";
			rep(j,sz(S[i]))cout<<S[i][j]<<" ";
			cout<<endl;
		}
	}
}