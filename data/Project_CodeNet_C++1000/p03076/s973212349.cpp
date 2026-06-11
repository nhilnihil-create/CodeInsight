#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int main(){
  vector<int> a(5);
  for(int i=0;i<5;i++)cin >> a[i];
  vector<int> P  = {0,1,2,3,4};
  int ans=INF;
  do{
    int sum=0;
    for(int i=0;i<5;i++){
      while(sum%10!=0)sum++;
      sum+=a[P[i]];
    }
    ans=min(ans,sum);
  }while(next_permutation(P.begin(),P.end()));
  cout << ans << endl;
}
