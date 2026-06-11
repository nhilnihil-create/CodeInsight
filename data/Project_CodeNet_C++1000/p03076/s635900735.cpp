#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> t(5); cin>>t[0]>>t[1]>>t[2]>>t[3]>>t[4];
  int min_time;
  min_time = ((t[0]+9)/10+(t[1]+9)/10+(t[2]+9)/10+(t[3]+9)/10+(t[4]+9)/10)*10-max({(200-t[0])%10,(200-t[1])%10,(200-t[2])%10,(200-t[3])%10,(200-t[4])%10});
  cout << min_time << endl;
  return 0;
}