#include<bits/stdc++.h>
 
#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>
 
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  if((a[0] == b[2])&&(a[1] == b[1])&&(a[2] == b[0])) cout << "YES" << endl;
  else cout << "NO" << endl;
}