#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int N;
vi solve(){
  vi res;
  if(N==3){
    res.push_back(2);
    res.push_back(3);
    res.push_back(25);
    return res;
  }
  res.push_back(2);
  res.push_back(4);
  res.push_back(3);
  res.push_back(9);
  int j=1,s=4;
  while(s<N-1&&j<5000){
    res.push_back(6*j+2);
    res.push_back(6*j+4);
    j++;
    s+=2;
  }
  if(j!=5000){
    if(N%2==1){
      res.push_back(6);
      return res;
    }
    else{
      return res;
    }
  }
  j=1;
  while(s<N-1&&j<2500){
    res.push_back(12*j+3);
    res.push_back(12*j+9);
    j++;
    s+=2;
  }
  if(j!=2500){
    if(N%2==1){
      res.push_back(6);
      return res;
    }
    else{
      return res;
    }
  }
  j=1;
  while(s<N){
    res.push_back(6*j);
    j++;
    s++;
  }
  return res;
}
int main(){
  cin>>N;
  vi res=solve();
  int rs=res.size();
  rep(i,rs) std::cout<<res[i]<<" ";
  std::cout<<"\n";
  return 0;
}
