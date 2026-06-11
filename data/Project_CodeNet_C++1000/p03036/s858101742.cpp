#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;

int main(){
 int r,d,x;
 cin >> r >> d >> x;
 for(int i = 0; i<10; i++){
     int xi = 0;
     xi = r*x-d;
     cout << xi << endl;
     x = xi;
 } 
 return 0;
 
}