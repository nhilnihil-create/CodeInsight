#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define rep(a,b,c) for(int a=1;a<=b;a+=c)
#define repp(a,b,c,d) for(int a=b;a<=c;a+=d)

const double PI=acos(-1);
const double EPS=1e-12;
const int MOD=1e9+7;
const int INF=1<<30;


using namespace std;


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string str;
	int win;
	cin>>str;
	win=15-str.length();
	repp(i,0,str.size()-1,1){
		if(str[i]=='o')win++;
	}
	if(win>=8)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
