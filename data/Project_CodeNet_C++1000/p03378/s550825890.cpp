#include <bits/stdc++.h>
using namespace std;
int main() {
 int n,m,x;
  cin >> n >>m >>x ;
  vector<int> P(m+1);
  for(int i=0;i<m;i++){
    cin >>P.at(i);}
  P[m]=0;
  sort(P.begin(), P.end()); 
  int cnt_a=0;
  int cnt_b=0;
for(int i=0;i<m+1;i++){
if(P[i] !=0 && P[i] <= x-1)cnt_a++;
  if(P[i] >= x+1 && P[i] <= n-1)cnt_b++;
  

}
  
  cout << min(cnt_a,cnt_b) <<endl;
  
}