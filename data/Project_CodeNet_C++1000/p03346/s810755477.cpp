#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, p[200009], q[200009];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> p[i];
    q[p[i]]=i;
  }
  int cur=q[1];
  int cnt=1;
  int mx=1;
  for(int i=2;i<=n;i++){
    if(q[i]<cur){
      cnt=0;
    }
    cnt++;
    cur=q[i];
    mx = max(mx, cnt);
  }
  cout << n - mx << endl;
}


