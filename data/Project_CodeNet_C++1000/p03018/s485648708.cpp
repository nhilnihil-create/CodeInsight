/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second < b.second);
}

int main(){

 string s;
 cin>>s;

  long long n = s.length();
  long long fronts=0,ans=0;

 for(int i=0;i<n;i++){

    if(s[i] == 'A'){
        fronts++;
        continue;
    }
    else if(i<n-1 && s[i] == 'B' && s[i+1] == 'C'){
        ans += fronts;
         i++;
         continue;
    }
     fronts = 0;
 }

  cout<<ans<<endl;

return 0;
}
