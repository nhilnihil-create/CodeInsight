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
#define MAX 10000

using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

bool compare(pair<int,int>p1, pair<int,int>p2){

  return p1.second > p2.second;
 }


 int main(){

  string a,b;
  cin>>a>>b;

  if(a.length() != b.length())
 {
 cout<<"No"<<endl;
  return 0; }

   long long pos=0;

  for(int i=0;i<a.length();i++){

    if(a[i] == b[0]){
        pos = i;
        break; }
  }

  //cout<<"the pos"<<pos<<endl;

  string emptys = "";
    long long ani=0,rot=pos;

  for(int i=rot;i<a.length();i++)
  {
     emptys += a[i];
  }

  for(int i = 0;i<rot;i++){
    emptys += a[i];
  }

  // cout<<"?? "<<emptys<<endl;

  if(emptys == b)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;


 return 0;
 }
