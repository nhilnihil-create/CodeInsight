/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include<bits/stdc++.h>
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

    int x=0,count=0;
    string s;
    unordered_map<int,int> mp;
    cin>>s;
    mp['A']=1,mp['C']=1,mp['T']=1,mp['G']=1;
    for (int i = 0; i <s.length(); ++i)
    {
    	   if(mp.find(s[i])!=mp.end()){
    	   	  count++;
    	   }else{
    	   	  x=max(x,count);
    	   	  count=0;
    	   }
    }
    x=max(x,count);
    cout<<x<<endl;

    return 0;
  }