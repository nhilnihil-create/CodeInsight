#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> time(N);
  vector<int> speed(N);
  cin >> time.at(0);
  if ( N != 1 ) {
    for(int i = 1 ; i < N ; i++) { 
      int x = 0;
      cin >> x ; 
      time.at(i) = time.at(i-1) + x;
    }  
  }
  
  for(int i = 0; i < N ; i++) { 
    cin >> speed.at(i); 
  } 
  int p = time.at(N-1)*2;  
  vector<double> limit(p); 
  vector<double> resp(p); 

  for(int i = 0; i < p ; i++) {
    limit.at(i) = 100;
    double ihalf = i * 0.5;
    for(int j = 0; j < N ; j++) {
      if ( ihalf + 0.05 >= time.at(j) ) { 
        continue; 
      }
      
      double lim = 0;
      if ( j == 0 ) {
        limit.at(i) = speed.at(j);
      }
      if ( j != 0 ) {
        if ( ihalf + 0.05 >= time.at(j-1) ) {
          lim = speed.at(j);
        }
        else {
          lim = speed.at(j) + time.at(j-1) - ihalf - 0.5 ;
        }
        
        if ( lim + 0.05 < limit.at(i) ) {
          limit.at(i) = lim;
        }
      }
      if ( j == N - 1 ) {
        lim = time.at(j) - ihalf - 0.5;
        if ( lim + 0.05 < limit.at(i) ) {
          limit.at(i) = lim;
        }
      }
    }
  }
  
  double v = 0;
/*  for(int i = 0; i < p ; i++) {
    if ( v + 0.5 <= limit.at(i) + 0.05 ) {
      v += 0.5;
    }
    else if ( v + 0.05 >= limit.at(i) + 0.5 ) {
      v -= 0.5;
    }
    resp.at(i) = v;
  }
*/
  resp.at(0) = 0.5;
  for(int i = 0; i < p-1 ; i++) {
    resp.at(i+1) = min( limit.at(i+1) , resp.at(i) + 0.5 );
  }

  double range2 = 0;
  for(int i = 0; i < p ; i++) {
    if ( i == 0) {
      range2 += resp.at(i) * 0.25;
    }
    else {
      range2 += (resp.at(i) + resp.at(i-1)) * 0.25;
    }
    /*range2 += resp.at(i); */
  }
  cout << setprecision(10) << range2 << endl;
}