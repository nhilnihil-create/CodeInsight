#include <iostream>
  #include <algorithm>
  #include <vector>
  #include <cmath>
#include <string>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <iomanip>
  #include <stack>
  #include <queue>
  #include <deque>
  using namespace std;
   
  int main(){
      long long m,k;
      cin>>m>>k;
      if(k>=(1<<m)){
          cout<<-1;
          return 0;
      }
      if(k==0){
          for(int i=0;i<(1<<m);i++){
              cout<<i<<' '<<i<< ' ';
          }
          return 0;
      }
      int x=0;
      for(int i=0;i<(1<<m);i++){
          if(k!=i)x^=i;
      }
      if(x!=k){
          cout<<-1;
          return 0;
      }
      cout << k << ' ';
      for(int i=0;i<(1<<m);i++){
          if(i!=k)cout<<i<<' ';
      }
      cout<<k<<' ';
      for(int i=(1<<m)-1;i>=0;i--){
          if(i!=k)
          cout<<i<< ' ';
      }
      return 0;
  }
