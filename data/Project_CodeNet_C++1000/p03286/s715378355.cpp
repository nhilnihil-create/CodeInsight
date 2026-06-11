#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int N,M;
int X[100],Y[100],h[100];

void gcl(int& x,int& y){
    if(x<y) swap(x,y);
    while(y>0){
        int t=x%y;
        x=y;
        y=t;
    }
    return;
}


int main(){
    int N;cin>>N;
    vector<int> ans;
  if(N==0){
    cout<<0<<endl;
    return 0;
  }  
    while(N!=0){
        int b=(abs)(N%(-2));
        ans.push_back(b);
        N=(N-b)/(-2);
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++){
      cout<<*it;
    }
  cout<<endl;
  return 0;
}