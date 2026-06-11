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
 cin >> n;
 LL ans = 0;
 LL b = 0, temp = 0;
 double c = 0;


 vector<int> seq(n);
 vector<int> x(n);
 forn(i,n){
     cin >> seq.at(i);
     x.at(i) = seq.at(i) - i;
 }

 sort(x.begin(), x.end());
if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
 if(n % 2){
     forn(i,n){
         ans += abs(x.at(i) - x.at(n/2-1));
     }
     forn(i,n){
         temp += abs(x.at(i) - x.at(n/2));
     }
     ans = min(ans, temp);
 }
 else{
     forn(i,n){
         ans += abs(x.at(i) - x.at(n/2));
     }
 }
 cout << ans << endl;
}
   
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    
  f();
 return 0;
}
