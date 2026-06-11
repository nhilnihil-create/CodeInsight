#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  string a;
  cin>>a;
  if(a[0]-'0'+a[1]-'0'+a[2]-'0'+a[3]-'0'==7){
    cout<<a[0]<<"+"<<a[1]<<"+"<<a[2]<<"+"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')+(a[1]-'0')+(a[2]-'0')-(a[3]-'0')==7){
    cout<<a[0]<<"+"<<a[1]<<"+"<<a[2]<<"-"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')+(a[1]-'0')-(a[2]-'0')+(a[3]-'0')==7){
    cout<<a[0]<<"+"<<a[1]<<"-"<<a[2]<<"+"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')+(a[1]-'0')-(a[2]-'0')-(a[3]-'0')==7){
    cout<<a[0]<<"+"<<a[1]<<"-"<<a[2]<<"-"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')-(a[1]-'0')+(a[2]-'0')+(a[3]-'0')==7){
    cout<<a[0]<<"-"<<a[1]<<"+"<<a[2]<<"+"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')-(a[1]-'0')+(a[2]-'0')-(a[3]-'0')==7){
    cout<<a[0]<<"-"<<a[1]<<"+"<<a[2]<<"-"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')-(a[1]-'0')-(a[2]-'0')+(a[3]-'0')==7){
    cout<<a[0]<<"-"<<a[1]<<"-"<<a[2]<<"+"<<a[3]<<"="<<7<<endl;
    return 0;
  }
  if((a[0]-'0')-(a[1]-'0')-(a[2]-'0')-(a[3]-'0')==7){
    cout<<a[0]<<"-"<<a[1]<<"-"<<a[2]<<"-"<<a[3]<<"="<<7<<endl;
    return 0;
  }
}