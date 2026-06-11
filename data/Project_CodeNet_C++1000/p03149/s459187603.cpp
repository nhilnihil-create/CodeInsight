#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  string s="    ";
  cin>>s[0]>>s[1]>>s[2]>>s[3];
  sort(s.begin(), s.end());
  cout<<(s=="1479"?"YES":"NO")<<endl;
  
}