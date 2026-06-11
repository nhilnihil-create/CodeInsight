#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int main(){
   int a,b,c,d; cin>>a>>b>>c>>d;
   if((abs(b-a)<=d&&abs(c-b)<=d) || abs(c-a)<=d) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
