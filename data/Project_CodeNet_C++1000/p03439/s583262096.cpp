#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  string s;
  cin>>N;
  int left=0;
  int right=N;
  vector<int> seat(N,-1);
  cout<<0<<endl;
  cin>>s;
  if(s!="Vacant"){
    if(s=="Male"){
      seat.at(0)=1;
    }else{
      seat.at(0)=0;
    }
    cout<<(left+right)/2<<endl;
    cin>>s;
    if(s!="Vacant"){
      while(s!="Vacant"){
        if(s=="Male"){
          seat.at((left+right)/2)=1;
        }else{
          seat.at((left+right)/2)=0;
        }
        if(((left+right)/2-left)%2==0){
          if(seat.at((left+right)/2)==seat.at(left)){
            left=(left+right)/2;
          }else{
            right=(left+right)/2;
          }
        }else{
          if(seat.at((left+right)/2)==seat.at(left)){
            right=(left+right)/2;
          }else{
            left=(left+right)/2;
          }
        }
        cout<<(left+right)/2<<endl;
        cin>>s;
      }
    }
  }
}
