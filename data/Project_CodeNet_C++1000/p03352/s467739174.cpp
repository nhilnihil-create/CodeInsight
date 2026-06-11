#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
  cin>>x;
  vector<int> v;
  for(int i=2; i<35; i++){
    int k=i*i;
    while(k<=1200){
      v.push_back(k);
      k *=i;
    }
  }
  v.push_back(1);
  sort(v.begin(), v.end());
  int ans=v[0];
  for(int i=0;;i++){
    if(v[i]>x) break;
    ans=v[i];
  }
cout<<ans<<endl;
}