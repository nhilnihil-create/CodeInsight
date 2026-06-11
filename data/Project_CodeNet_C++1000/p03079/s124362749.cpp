#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int main(){
  vector<int>e(3);
  for(int i=0;i<3;i++)cin>>e[i];
  sort(e.begin(),e.end());
  if(e[0]==e[2])puts("Yes");
  else puts("No");
  return 0;
}
