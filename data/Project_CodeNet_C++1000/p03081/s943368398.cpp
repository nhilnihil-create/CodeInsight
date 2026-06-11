#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
int main(){
  int n,q,ans,l,r,h,idx;
  char now_c;
  string s;
  cin >> n >> q;
  char t[q],d[q];
  cin >> s;
  for(int i=0;i<q;i++){
    cin >> t[i]>>d[i];
  }
  ans = n;
  l = -1;
  r = n;
  while(l+1<r){
    h = (l+r)/2;
    idx = h;
    now_c = s[idx];
    for(int i=0;i<q;i++){
      if(now_c==t[i]){
        idx += (d[i]=='L')?-1:1;
        if(idx<0||idx>=n){
          break;
        }
        now_c = s[idx];
      }
    }
//    cout <<l<<" "<<r<< h<<"idxx"<<idx<<endl;
    if(idx<0){
      l = h;
    }else{
      r = h;
    }
  }
  ans -= l+1;

  l = -1;
  r = n;
  while(l+1<r){
    h = (l+r)/2;
    idx = h;
    now_c = s[idx];
    for(int i=0;i<q;i++){
      if(now_c==t[i]){
        idx += (d[i]=='L')?-1:1;
        if(idx>=n||idx<0){
          break;
        }
        now_c = s[idx];
      }
    }
    if(idx>=n){
      r = h;
    }else{
      l = h;
    }
  //  cout <<l<<" "<<r<< h<<"idx"<<idx<<endl;
  }
  ans -= n-r;
  cout << ans<<endl;
}
