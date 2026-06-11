#include <bits/stdc++.h>
using namespace std;
#define storpa ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    storpa;
    int n, m, k, a, b[31]={0}, cnt=0;
    vector<int>vec;
    cin >> n >> m;
    for(int i=0; i<n; i++){
      cin >> k;
      for(int j=0; j<k; j++){
        cin >> a;
        b[a]++;
        vec.push_back(a);
      }
    }
    for(int i=0; i<=m; i++){
      if(b[i]==n){
        cnt++;
      }
    }
    cout << cnt;
}
