#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,sum,j;
  sum=0;
  j=0;
  cin >> n;
  vector<int> Ls(n);
  for (int i=0 ; i< n ;i++){
    cin >> Ls.at(i);
  }
  for (int i =0 ; i < n; i++){
    sum+=Ls.at(i);
  }
  for (int i=0; i <n ; i++){
    if(sum-Ls.at(i) <= Ls.at(i)){
      j++;
    }
  }
  if (j==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" <<endl;
  }
}
