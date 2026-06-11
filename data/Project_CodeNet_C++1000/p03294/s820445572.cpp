#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
void f(){
 int n;
 LL ans = 0;
 cin >> n;
 vector<int> in(n);

 forn(i,n){
     cin >> in.at(i);
     ans += in.at(i) - 1;
 }
 cout << ans << endl;
}
   
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    
  f();
 return 0;
}