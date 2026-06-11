#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
//#include <functional>
#include <queue>
//#include <stack>
//#include <set>
#include <cmath>
//#include <bitset>
#include <map>
using namespace std;
typedef long long ll;



int main() {
  int N;
  cin >> N;
  int A[N];
  ll S[N];
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(i==0) S[i] = A[i];
    else S[i] = S[i-1] + A[i];
  }
  ll ans =INT_MAX;
  for(int i=1; i < N-2; i++){
    int lb = 0;
    int rb = i-1;
    while(rb - lb >1){
      int mid = (rb + lb)/2;
      if(S[mid] < ((double) S[i])/2.)     {
	lb = mid;       
      }
      else{
	rb = mid;
      }
    }
    if(abs(S[i] - S[rb] - S[rb]) < abs(S[i] - S[lb] - S[lb])) lb = rb;


    int lb_2 = i+1;
    int rb_2 = N-2;
    while(rb_2 - lb_2 >1){
      int mid = (rb_2 + lb_2)/2;
      if(abs (S[N-1] - S[mid]) >= ((double) (S[N-1] - S[i]))/2.) {
	lb_2 = mid;
      } 
      else{
        rb_2 = mid;
      } 
    }
    //    cout << lb_2 << " " << rb_2 << endl;
    if(abs(S[N-1] - S[rb_2] - (S[rb_2]-S[i])) < abs(S[N-1] - S[lb_2] - (S[lb_2] - S[i]))) lb_2 = rb_2;
    //        cout << lb << " " << i << " " << lb_2 << endl;
      ll B = S[lb];
      ll C = S[i] - B;
      ll D = S[lb_2] - C - B;
      ll E = S[N-1] - D -C -B;      
      ans = min (ans,max(max(B,C),max(D,E)) - min(min(B,C),min(D,E)));
      
      //            cout << ans << endl;
  }
  
  cout << ans << endl;

}
