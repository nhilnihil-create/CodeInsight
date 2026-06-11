#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string s1,s2,s3;
  cin >> s1;
  cin >> s2;
  cin >> s3;
  string ans = "";
  ans += s1[0];
  ans += s2[1];
  ans += s3[2];
  cout << ans << endl;
}
