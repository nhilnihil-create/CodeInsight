#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  vector<int> A(4);
  for(int i=0;i<6;i++){
    int a;
    cin>>a;
    A[a-1]++;
  }
  for(int i:A)
    if(i==3){
      puts("NO");
      return 0;
    }
  puts("YES");
}