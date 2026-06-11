#include <bits/stdc++.h>
using namespace std;

int main() {
 int r,D;

 vector<int>vec(10);
 cin>>r>>D>>vec[0];
 for(int i=0;i<10;i++){
   vec[i+1]=r*vec[i]-D;
   cout<<vec[i+1]<<endl;
 }
}
   
  
  