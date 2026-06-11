#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  string s; cin >> s;
  int retval = 1000;
  for (int i=0;i<s.size()-2;i++){
    int d = stoi(s.substr(i,3));
    if (abs(d-753)<retval) retval = abs(d-753);
  }

  cout << retval << endl;
  
  // cout << fixed << setprecision(6);
  return 0;
}
