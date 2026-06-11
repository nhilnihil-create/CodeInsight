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
    int n,y=1e8,count=0;
    cin>>n;
    int a[n];
    for (int i = 0; i <n; ++i)
    {
    	cin>>a[i];
    }
  
    for (int i = 0; i <n; ++i)
    {
    	int x=1<<1;
    	while(a[i]%x==0){
    		x=x<<1;
    		count++;
    	}
    	y=min(y,count);
    	count=0;
    }
    cout<<y<<endl;
    return 0;
  }