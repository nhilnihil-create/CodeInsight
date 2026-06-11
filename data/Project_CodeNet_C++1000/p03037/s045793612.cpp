#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;	cin >> n >> m;
  int left=1;
  int right=n;
  
  for(int i=0;i<m;i++){
    int L,R;	cin >> L >> R;
    if(left<L)	left=L;
    if(R<right)	right=R;
  }
  cout << max(right-left+1,0);
}