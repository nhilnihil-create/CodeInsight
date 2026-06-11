#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  string s;cin>>s;
  if((int)s.size()==3)reverse(s.begin(), s.end());
  cout<<s<<endl;
}