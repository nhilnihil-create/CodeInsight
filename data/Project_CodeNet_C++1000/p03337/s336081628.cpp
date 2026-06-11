#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int main(){
   int a,b; cin>>a>>b;
   int ans=max(a+b,max(a-b,a*b));
   cout<<ans<<endl;
   return 0;
}
