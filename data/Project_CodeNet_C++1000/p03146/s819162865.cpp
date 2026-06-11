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
  set<int> S;
  int idx = 1;
  while (true){
    if (S.count(s)) break;
    else S.insert(s);

    if (s%2) (s *= 3) += 1;
    else s /= 2;
    
    idx++;
  }

  cout << idx << endl;
  
  // cout << fixed << setprecision(10);
  
  return 0;
}

