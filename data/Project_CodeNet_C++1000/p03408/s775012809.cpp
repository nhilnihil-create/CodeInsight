#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N ;  //NM出力
  cin >> N ;
  string b[N];
  for ( int i=0 ; i<N ; i++){
    cin >> b[i] ;
  }
   int M ;
  cin >> M ;
  string r[M];
  for ( int i=0 ; i<M ; i++){
    cin >> r[i] ;
  }
  int ben[N] ;
  int mx=0 ;
  for (int i=0 ; i <N ; i++){
      ben[i]=0;
    }
  int count[N];
    for (int i=0 ; i <N ; i++){
      count[i]=0;
    }
    for (int i=0 ; i<N ; i++){
      if (b[i] == "A"){
        continue ;
      }else if (b[i] !="A"){
        for (int j=i ; j<N ; j++){
          if (b[i]==b[j]){
            count[i]++;
              b[j] == "A";
          }
        }
        for (int j=0 ; j<M ; j++){
          if (b[i]==r[j]){
            count[i]--;
          }
        }
        if (count[i] > 0){
          ben[i]+=count[i];
        }
      }
      mx = max(mx,ben[i]) ;
    }
  cout << mx << endl;
}
       