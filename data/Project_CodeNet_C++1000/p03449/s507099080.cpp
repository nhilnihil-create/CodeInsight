#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
vector<vector<int>> a(2,vector<int>(n));
for(int i=0;i<2;i++){
  for(int j=0;j<n;j++){
  cin >> a[i][j];
  }
}
int sum;
int s=-1;
if(n>=2){
for(int i=0;i<=n-1;i++){
sum=0;  
int j=0;  
while(j<=i && j<=n-1){
  sum+=a[0][j];
  if(j==i)break;
  else j++;
  }
while(j>=i && j<=n-1)sum+=a[1][j],j++;
s=max(s,sum);  
}
cout << s << endl;
}
else cout << a[0][0]+a[1][0] << endl;  
}  


