#include<iostream>
#include<cstring>
using namespace std;
int n,tm[1001]; char c1[1001],c2[1001],c3[1001]; int main() {int ans = 0; cin>>n>>c1>>c2>>c3; for(int i=0;i<n;i++) { memset(tm,0,sizeof(tm)); tm[ c1[i] ]++;tm[ c2[i] ]++;tm[ c3[i] ]++; ans += 3 - max( tm[ c1[i] ] , max( tm[ c2[i] ],tm[ c3[i] ] )  );   }  cout<<ans;  }