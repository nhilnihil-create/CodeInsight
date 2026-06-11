#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int a[N];
int b[N];
bool chan[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  for(int i = 1; i <= n; i ++ )
    cin >> b[i];
  vector<int> shit;
  ll sum = 0;
  for(int i = 1; i <= n; i ++ ){
    shit.push_back(a[i] - b[i]);
    sum += a[i] - b[i];
  }
  if(sum < 0){
    cout << -1;
    return 0;
  }
  sort(shit.begin(), shit.end());
  int p = n-1;
  ll ad;
  for(int i = 0 ; i < n; i ++ ){
    if(shit[i] >= 0) break;
    while(shit[i] < 0){
      chan[i]=true;
      chan[p]=true;
      ad = min(shit[p],-shit[i]);
      shit[i] += ad;
      shit[p] -= ad;
      if(shit[p]==0)p--;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i ++ )
    ans += chan[i];
  cout << ans;
  return 0;
}
