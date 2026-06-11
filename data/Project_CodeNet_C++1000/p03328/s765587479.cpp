#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int sum(int n){
   if(n==1) return 1;
   else return sum(n-1)+n;
}
int main(){
   int a,b; cin>>a>>b;
   int ans=b-a;
   cout<<sum(ans)-b<<endl;
   return 0;
}
