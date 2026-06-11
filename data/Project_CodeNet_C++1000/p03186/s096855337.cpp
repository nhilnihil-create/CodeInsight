#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  
  if(A+B>=C){
    cout <<C+B << endl;
  }else{
    cout  << A+B+1+B << endl;
  }
}