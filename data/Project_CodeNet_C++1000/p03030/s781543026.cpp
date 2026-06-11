#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<tuple<string,int,int>> vec;
  for(int i=1;i<=n;i++){
    string s;
    int a;
    cin>>s>>a;
    a=-a;
    vec.push_back(tie(s,a,i));
  }
  sort(vec.begin(),vec.end());
   rep(i,n){
  cout<<get<2>(vec[i])<<endl;
   }
}
                                   