#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int main(){
   string s; cin>>s;
   int cnt=0;
   int l=0,r=0;
   rep(i,s.size()){
      if(s[i]=='0') l++;
      else r++;
   }
   int ans=min(l,r);
   cout<<ans*2<<endl;
   return 0;
}
