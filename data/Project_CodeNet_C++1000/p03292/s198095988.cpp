#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int a[3];
  rep(i,3) cin >> a[i];
  
  int array[3];
  rep(i,3) array[i] = i;
  
  int ans = 1001001001;
  do{
    int temp = abs( a[ array[1] ] - a[ array[0] ] );
    temp += abs( a[ array[2] ] - a[ array[1] ] );
    ans = min(ans,temp);
  }while(next_permutation(array,array+3));
  
  cout << ans << endl;
  
  return 0;
}
                      
                      