#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int cnt[n]={};
  for(int i=1; i<n; i++){
    if(s[i-1]=='A' && s[i]=='C') cnt[i] = cnt[i-1]+1;
    else cnt[i] = cnt[i-1];
  }
  for(int i=0; i<q; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(a==0) cout << cnt[b] << endl;
    else cout << cnt[b] - cnt[a] << endl;
  }
  return 0;
}
