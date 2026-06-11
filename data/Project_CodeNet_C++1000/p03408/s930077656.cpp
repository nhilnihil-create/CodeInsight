#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,max=0,total=0;
  cin >> n;
  string strn[n];
  for(int i=0;i<n;i++)
    cin >> strn[i];
  cin >> m;
  string strm[m];
  for(int t=0;t<m;t++)
    cin >> strm[t];
  for(int i=0;i<n;i++){
    for(int l=0;l<n;l++){
      if(strn[i]==strn[l])
        total++;
    }
    for(int t=0;t<m;t++){
      if(strn[i]==strm[t])
        total--;
    }
    if(total>max)
      max = total;
    total=0;
  }
  cout << max << endl;
  
  
}
