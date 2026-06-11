#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long>a(n);
  vector<long>b(n);
  int i,j;
  long sumA = 0;
  long sumB = 0;
  vector<long>sa(n);
  for(i=0;i<n;i++){
    cin >> a[i];
    sumA += a[i];
  }
  for(i=0;i<n;i++){
    cin >> b[i];
    sa[i] = a[i]-b[i];
    sumB += b[i];
  }
  if(sumB > sumA)cout << -1 << endl;
  else{
    sort(sa.begin(),sa.end());
    i=0;
    j = n-1;
    long tmp = 0;
    while(sa[i]<0){
      tmp = -sa[i];
      i++;
      while(sa[j]<tmp){
        tmp -= sa[j];
        j--;
      }
      sa[j]-=tmp;
    }

    if(sa[0]>=0)cout << 0 << endl;
    else cout << i + (n-j) << endl;
  }


}
