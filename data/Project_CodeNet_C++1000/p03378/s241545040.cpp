#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int>a(m);
    rep(i,m)cin>>a[i];
    int cntunder=0;
    int cntover=0;
    for(int i=0;i<m;i++){
      if(a[i]<x)cntunder+=1;
      else break;
    }
    for(int i=m-1;i>=0;i--){
        if(a[i]>x)cntover+=1;
        else break;
    }
    cout<<min(cntunder,cntover)<<endl;
}
