#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  N++;
  int M=to_string(N).size()-1;
  cout<<M*9+to_string(N)[0]-'1'<<endl;
}