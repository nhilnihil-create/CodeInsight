#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;cin >> n >> q;
  string s;cin >> s;
  vector<char> d(q),t(q);
  for(int i=0;i<q;i++){
    cin >> d[i] >> t[i];
  }
  int ll=-1,lr=n;
  while(lr-ll>1){
    int mid=(ll+lr)/2;
    char now=s[mid];
    int num=mid;
    bool f=true;
    for(int i=0;i<q;i++){
      if(d[i]==now){
        if(t[i]=='L'){
          num--;
          if(num==-1){
            f=false;
            break;
          }
          now=s[num];
        }
        else{
          num++;
          if(num==n){
            break;
          }
          now=s[num];
        }
      }
    }
    if(!f){
      ll=mid;
    }
    else{
      lr=mid;
    }
  }
  int rl=-1,rr=n;
  while(rr-rl>1){
    int mid=(rl+rr)/2;
    char now=s[mid];
    int num=mid;
    bool f=true;
    for(int i=0;i<q;i++){
      if(d[i]==now){
        if(t[i]=='L'){
          num--;
          if(num==-1){
            break;
          }
          now=s[num];
        }
        else{
          num++;
          if(num==n){
            f=false;
            break;
          }
          now=s[num];
        }
      }
    }
    if(!f){
      rr=mid;
    }
    else{
      rl=mid;
    }
  }
  cout << max(0,rr-ll-1) << endl;
}