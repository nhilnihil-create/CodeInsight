/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include <bits/stdc++.h>
using namespace std;

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
    int n,m,x,k=0,count=0;
    unordered_map<int,int> mp;
    cin>>n>>m>>x;
    int a[m];
    for (int i = 0; i <m; ++i)
    {
    	cin>>a[i];
    	mp[a[i]]=1;
    }
    
    for (int i=x; i<=n; ++i)
    {
    	if(mp.find(i)!=mp.end()){
    		k++;
    	}
    }

    for (int i =x; i>=0; i--)
    {
    	if(mp.find(i)!=mp.end()){
    		count++;
    	}
    }
    cout<<min(count,k)<<endl;
    return 0;
  }