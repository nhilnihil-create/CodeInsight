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
//const int MAX=;



int main(){
	int N;
	cin>>N;
	int r=0;
	int b=0;
	rep(i,N){
		char c;
		cin>>c;
		if(c=='R')r++;
		if(c=='B')b++;
	}
	if(r>b)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}