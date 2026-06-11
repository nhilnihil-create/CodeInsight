#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int q,w,e,r; cin>>q>>w>>e>>r;
  if(q+w<e+r)cout << "Right";
  if(q+w==e+r)cout << "Balanced";
  if(q+w>e+r)cout << "Left";
}