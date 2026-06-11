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
 int n, k;

 cin >> n >> k;
 int ans = 0, one = 0, left, right, temp, rem = 0;

 //vector<int> seq(n);
 forn(i,n){
     cin >> temp;
     if(temp == 1)
        one = i;
 }
 /*
 left = one;
 right = (n - 1) - one;
 if((k - 1) > left && left > 0){
     right -= (k - 1) - left;
     left = 0;
     ans++;
 }
if((k - 1) > right && right > 0){
     left -= (k - 1) - right;
     right = 0;
     ans++;
 }

 if(left > 0){
    ans += left / (k - 1);
    if(left  % (k-1) != 0){
        ans++;
        if(left / (k - 1) != 0)
            rem += (k-1) - left % (k-1);
    }
 }
 if(right > 0){
    ans += right /(k - 1);
    if(right % (k-1) != 0){
        ans++;
        if(right /(k - 1) != 0)
        rem += (k-1) - right % (k-1);
    }
 }
 if(rem > (k-1))
    ans--;
*/
ans = 1;
while(k + (ans-1)*(k-1) < n){
    ans++;
}
 cout << ans << endl;
}
   
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    
  f();
 return 0;
}