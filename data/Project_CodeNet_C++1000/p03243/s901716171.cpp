#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin>>N;
  
  // int A=max({N/100,N%100/10,N%100%10});
  //ありうる答え　999 888 777 666 555 444 333 222 111
for(int i =0 ;i <10 ; i++)
  if(111*i>=N &&111*(i-1)<N)
   cout<<i*111;
    
}
