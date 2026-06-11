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
  int s; cin >> s;
  vector<int> passed(10000000,-1);
  int i = 1;

  while (1){
    if (passed[s]==-1) passed[s] = i;
    else {
      cout << i << endl;
      break;
    }

    if (s%2==0) s = s/2;
    else s = 3*s + 1;

    i++;
  }

  // cout << fixed << setprecision(6);
  return 0;
}
