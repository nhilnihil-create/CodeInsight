#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 int a,b ;
 cin >> a >> b;
 int mx=-50000;
  mx= max(mx,a+b);
  mx= max(mx,a-b);
  mx= max(mx,a*b);
   cout << mx << endl;
  
     
}