#include <bits/stdc++.h>

using namespace std;

int main(){
 int n,a,b; 
  cin >> n >> a >> b;
  
  int p;
  int res1=0,res2=0,res3=0;
  for(int i=0;i<n;i++){
    cin >>p;
    if(p<=a) res1++;
    else if(p<=b) res2++;
    else res3++;
  }
 cout << min(res1,min(res2,res3)) << endl;
   
}