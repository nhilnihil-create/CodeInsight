#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> vct(n);
  for(int i=0;i<n;i++) cin >> vct[i];
  sort(vct.begin(),vct.end());
  reverse(vct.begin(),vct.end());
  int A=0;
  int B=0;
  for(int i=0;i<n;i++){
      if(i%2==0){
          A+=vct[i];
      }else{
          B+=vct[i];
      }
  }
  cout<<A-B<<endl;
  }