#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> t(5); cin>>t[0]>>t[1]>>t[2]>>t[3]>>t[4];
  int min_time=1000;
  sort(t.begin(),t.end());
  do {
    int time;
    time=((t[0]+9)/10+(t[1]+9)/10+(t[2]+9)/10+(t[3]+9)/10)*10+t[4];
 	min_time = min(min_time, time); 
  } while (next_permutation(t.begin(),t.end()));
  cout << min_time << endl;
  return 0;
}
