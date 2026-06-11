#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i,ans=(1<<29);
  for(i=0;i<s.size()-2;i++){
    int a=s[i]-'0',b=s[i+1]-'0',c=s[i+2]-'0';
    ans=min(ans,abs(753-(100*a+10*b+c)));
  }
  cout << ans << endl;
}