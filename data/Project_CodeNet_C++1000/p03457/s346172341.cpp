#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
 int n;
 cin>>n;
 
 int t,x,y;
 int currentt = 0;
 int currentx = 0;
 int currenty = 0;
 bool a = true;
 
 for(int i = 0;i<n;i++) {
 cin >>t>>x>>y;
   if(t - currentt < abs(x - currentx) + abs(y - currenty) || (t-currentt)%2 != abs(x - currentx + y - currenty)%2) {
   a = false;
   break;
    }
  currentt = t;
  currentx = x;
  currenty = y;
  }
 
 if(a) {
  cout << "Yes" << endl;
  } else {
   cout << "No" << endl;
   }
   
}