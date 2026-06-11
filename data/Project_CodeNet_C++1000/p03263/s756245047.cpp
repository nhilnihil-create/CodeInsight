#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
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
  for(int i=0;i<=H;i++){
    for(int j=0;j<=W;j++)if(a[i][j]&1){
      if(i<H&&j<W){
        if(a[i+1][j]&1){
          a[i+1][j]++;
          a[i][j]--;
          v.push_back(make_tuple(i,j,i+1,j));
          cnt++;
        }else{
          a[i][j+1]++;
          a[i][j]--;
          v.push_back(make_tuple(i,j,i,j+1));
          cnt++;
        }
      }else if(i<H){
        a[i+1][j]++;
        a[i][j]--;
        v.push_back(make_tuple(i,j,i+1,j));
        cnt++;
      }else if(j<W){
        a[i][j+1]++;
        a[i][j]--;
        v.push_back(make_tuple(i,j,i,j+1));
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  int a,b,c,d;
  int n=v.size();
  for(int i=0;i<n;i++){
    tie(a,b,c,d)=v[i];
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
  }
  return 0;
}