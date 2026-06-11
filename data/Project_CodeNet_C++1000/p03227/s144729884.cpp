#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  string s;
  cin>>s;
  if(s.length()==2){
    cout<<s<<endl;
  }else{
    reverse(s.begin(),s.end());
    cout<<s<<endl;
  }

}
