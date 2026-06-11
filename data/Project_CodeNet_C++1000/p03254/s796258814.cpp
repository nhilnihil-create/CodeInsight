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
    int n,x;
 
    cin>>n>>x;
    int a[n];
    for (int i = 0; i <n; ++i)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    int i=0;
    while(x>0 && i<n){
        x-=a[i];
        if(x<0){
        	break;
        }
        i++;
    }
    if(x>0)
      cout<<i-1<<endl;
    else
      cout<<i<<endl;
    return 0;
  }