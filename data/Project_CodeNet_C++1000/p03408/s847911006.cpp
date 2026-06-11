#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,cnt1=0,cnt2=0;
  string tmp;
  cin >> n;
  vector<string> linen(n);
  for(int i=0;i<n;i++){
    cin >> tmp;
    linen.at(i)=tmp;
  }
  cin >> m;
  vector<string> linem(m);
  for(int i=0;i<m;i++){
    cin >> tmp;
    linem.at(i)=tmp;
  }
  for(int i=0;i<n;i++){
    tmp=linen.at(i);
    for(int j=0;j<n;j++){
	  if(tmp==linen.at(j))cnt2++;
    }
    for(int j=0;j<m;j++){
      if(tmp==linem.at(j))cnt2--;
    }
    if(cnt2>=cnt1)cnt1=cnt2;
    cnt2=0;
  }
  if(cnt1<0)cnt1=0;
  cout << cnt1 << endl;
}