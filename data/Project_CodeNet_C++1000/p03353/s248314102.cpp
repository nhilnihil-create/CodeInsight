#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int k;
  cin>>k;
  int n=s.size();
  int as=min(k,5);
  vector<string>a;
  rep(i,n){
    string e="";
    rep2(j,i,n){
      e+=s.at(j);
      if(as>0){
        bool ch=true;
        rep(l,a.size()){
          if(a.at(l)==e){
            ch=false;
          }
        }
        if(ch){ 
          a.push_back(e);
          as--;
        }
      }
      else{
        sort(a.begin(),a.end());
        if(a.at(a.size()-1)>e){
          bool ch=true;
          rep(l,a.size()){
            if(a.at(l)==e){
              ch=false;
            }
          }
          if(ch){ 
            a.at(a.size()-1)=e;
          }
        }
        else{
          break;
        }
      }
    }
  }
  sort(a.begin(),a.end());
  cout<<a.at(k-1)<<endl;
}