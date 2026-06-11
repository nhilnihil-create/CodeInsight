#include<bits/stdc++.h>
using namespace std;
#define test(a) cout << "*" << a << endl;
#define rep0(i,n) for(i=0;i<n;i++)
int main(){
  vector<int>vec(3);
  int i;
  
  rep0(i,3){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());  
  //rep0(i,3) test(vec[i]);
  
  cout << (vec[2]-vec[1])+(vec[1]-vec[0]) <<endl;
 
  //test(a[0]);
  
}