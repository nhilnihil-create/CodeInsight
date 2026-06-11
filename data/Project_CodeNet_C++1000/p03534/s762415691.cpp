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

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
//const int MAX=;
const int MOD=1e9+7;

int main(){
	string S;
	cin>>S;
	int l=S.size();
	int p[3];
	rep(i,3)p[i]=0;
	rep(i,l){
		char x=S[i];
		int a=x-'a';
		p[a]++;
	}
	
	bool ok=true;
	if(abs(p[0]-p[1])>1)ok=false;
	if(abs(p[1]-p[2])>1)ok=false;
	if(abs(p[2]-p[0])>1)ok=false;
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}