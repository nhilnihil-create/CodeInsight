//
//  main.cpp
//  CoderW
//
//  Created by Minoru Hayashi on 2020/02/22.
//  Copyright © 2020 Minoru Hayashi. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(void){
  
  int N, M;
  
  cin >> N >> M;
  
  long long x[N], y[N], z[N];
  
  long long P[N];
  
  int fx, fy, fz;
  
  for (int i=0; i<N; i++){
    cin >> x[i] >> y[i] >> z[i];
  }
  
  long long maxP = 0;
  
  for (int b=0; b<8; b++){
    // b2 b1 b0 : fz fy fx :: 0 means -  1 means +
    fx = (b & 0b001) ? 1:-1;
    fy = (b & 0b010) ? 1:-1;
    fz = (b & 0b100) ? 1:-1;
    
    for (int j=0; j<N; j++){
      P[j]= fx * x[j] + fy * y[j] + fz * z[j];
    }
/*
    for (int i=0; i<N; i++){
      cout << i << '/' << P[i] << endl;
    }
*/
    sort(P, P+N, greater<>());
/*
    for (int i=0; i<N; i++){
      cout << i << ':' << P[i] << endl;
    }
 */
    long long tmp = 0;
    
    for (int i=0; i<M; i++){
      tmp += P[i];
    }
    maxP = max(maxP, tmp);
    
//    cout << "maxP[" << b << "]=" << maxP << endl;
  }
  
  cout << maxP << endl;
  
  return;
}



int main(int argc, const char * argv[]) {


    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);
  
  
  solve();
  
  return 0;
}
