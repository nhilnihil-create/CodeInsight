#include<iostream>
#include<list>
using namespace std;
#define df 0

int main(){
  if(df) printf("*debug mode*\n");
  int n,q; cin >> n >> q;
  string str; cin >> str;
  pair<char,char> query[q];
  for(auto& qr: query){
    cin >> qr.first >> qr.second;
  }
  int l=0,r=n;
  for(int i=q-1;i>=0;i--){
    char a=query[i].first,dir=query[i].second;
    if(dir=='R'){
      if(str[r-1]==a)r--;
      if(l>0 && str[l-1]==a)l--;
    }
    else{
      if(r<n && str[r]==a)r++;
      if(str[l]==a)l++;
    }
    if(df)printf("%d %d\n",l,r);
  }
  cout << r-l;
  
}

/// confirm df==0 ///
