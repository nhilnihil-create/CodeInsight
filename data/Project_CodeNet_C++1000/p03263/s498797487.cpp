#include<iostream>
#include<vector>
#include<tuple>
#include<utility>
using namespace std;

int H,W;
int a[503][503];

int main(){
  cin>>H>>W;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>a[i][j];
    }
  }
  int cnt=0;
  vector<tuple<int,int,int,int> > v;
  for(int i=1;i<=H;i++){
    for(int j=1;j<W;j++){
      if(a[i][j]&1){
        a[i][j+1]++;
        a[i][j]--;
        v.push_back(make_tuple(i,j,i,j+1));
        cnt++;
      }
    }
  }
  for(int i=1;i<H;i++){
    if(a[i][W]&1){
      a[i+1][W]++;
      a[i][W]--;
      v.push_back(make_tuple(i,W,i+1,W));
      cnt++;
    }
  }
  cout<<cnt<<endl;
  int n=v.size();
  int a,b,c,d;
  for(int i=0;i<n;i++){
    tie(a,b,c,d)=v[i];
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
  }
  return 0;
}