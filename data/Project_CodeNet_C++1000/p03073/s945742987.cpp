#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LIMIT 1000000007 //10^9+7
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

int main(){
	string S;cin>>S;
  int L = 0;
  int ok_0 = 0; //0101...
  int ok_1 = 0; //1010...

  for(char x: S){
    int c = x-'0';
    if(L%2==c)ok_0++;
    if(L%2!=c)ok_1++;
    L++;
  }

  int err = L - max(ok_0, ok_1);

  cout<<err<<endl;
}