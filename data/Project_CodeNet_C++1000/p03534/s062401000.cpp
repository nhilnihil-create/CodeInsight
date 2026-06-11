#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin>>s;
  int n=s.size();

  int alp[3]={};
  for(int i=0;i<n;i++){
    alp[s[i]-'a']++;
  }

  int three=0,four=0;
  for(int i=0;i<3;i++){
    if(alp[i]==n/3) three++;
    else if(alp[i]==n/3+1) four++;
  }

  if(three==3-n%3&&four==n%3) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}
