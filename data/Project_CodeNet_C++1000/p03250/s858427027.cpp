#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

  
int main(){
  int a,b,c;
  cin >> a>> b>>c;
  int x,y,z;
  x=max(a,max(b,c));
 if(x==a) cout <<a*10+b+c<< endl;
  else if(x==b) cout << b*10+a+c <<endl;
  else if(x==c) cout << c*10+a+b <<endl;   
}
 