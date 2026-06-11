/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

void debug(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

}

  int main() {
    debug();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,c,res=0,count=0;
    cin>>n>>m>>c;
  
   int b[m],a[n][m];
   for(int i=0; i<m; i++){
   	 cin>>b[i];
   }
   for(int i=0; i<n; i++){
   	for(int j=0; j<m; j++){
   		cin>>a[i][j];
   		res+=(b[j]*a[i][j]);
   	}
   	if((res+c)>0){
   		count++;
   	}
   	res=0;
   }
   cout<<count<<endl;
    return 0;
  }