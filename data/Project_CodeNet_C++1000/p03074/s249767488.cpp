#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

int main() {
  int N,K;
  string s;
  cin>>N>>K>>s;
  vector<int64_t>one;
  vector<int64_t>zero;
  if(s[0]=='0'){one.push_back(0);}
  for(int i=0;i<N;i++){
    if(s[i]=='1'){
      int cnto=1;
      while(i+1<N&&s[i+1]=='1'){cnto++;i++;}
      one.push_back(cnto);
    }
    if(s[i]=='0'){
      int cntz=1;
      while(i+1<N&&s[i+1]=='0'){cntz++;i++;}
      zero.push_back(cntz);
    }
  }
  if(s[N-1]=='0'){one.push_back(0);}
  
//  for(int i=0;i<one.size();i++){
//    cout<<one[i]<<" ";
//  }cout<<"aa"<<endl;
// for(int i=0;i<zero.size();i++){
//   cout<<zero[i]<<" ";
//  }cout<<"bb"<<endl;
  
  int a=one.size(),b=zero.size();
  for(int i=0;i<(int)one.size();i++){
    if(i>0){one[i]+=one[i-1];}
  }

  for(int i=0;i<(int)zero.size();i++){
    if(i>0){zero[i]+=zero[i-1];}
  }

  int MAX=0;
 // cout<<a<<" "<<b<<endl;
  for(int i=0;i<(int)one.size();i++){
    int r=0;
    if(K>=zero.size()){
      r=one[a-1];
      if(b-1>=0){r+=zero[b-1];}
    }//間に挟むのでi+K
    else if(i==0&&i+K<=a-1){r=one[i+K]+zero[i+K-1];}
    else if(i>0&&i+K<=a-1){r=one[i+K]-one[i-1]+zero[i+K-1]-zero[i-1];}
    //cout<<r<<endl;
    chmax(MAX,r);
  }
  cout<<MAX<<endl;
  return 0;
}
