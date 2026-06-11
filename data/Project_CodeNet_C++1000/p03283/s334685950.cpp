#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int>> t(n,vector<int>(n,0));
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    t.at(l).at(r)++;
  }
  vector<vector<int>> a(n,vector<int>(n,0));
  for(int w=0;w<n;w++){
    for(int i=0;i+w<n;i++){
      if(w==0)
        a[i][i+w]=t.at(i).at(i+w);
      else
        a[i][i+w]=a[i][i+w-1]+a[i+1][i+w]-a[i+1][i+w-1]+t.at(i).at(i+w);
    }
  }
  for(int i=0;i<q;i++){
    int pi,qi;
    cin>>pi>>qi;
    pi--;
    qi--;
    cout<<a[pi][qi]<<endl;
  }
}