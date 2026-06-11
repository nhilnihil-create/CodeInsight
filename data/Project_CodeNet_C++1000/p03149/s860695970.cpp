#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int a[4];
  for(int i = 0 ; i < 4; i ++ )
    cin >> a[i];
  sort(a,a+4);
  if(a[0]==1 && a[1] == 4 && a[2] == 7 && a[3] == 9){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}
