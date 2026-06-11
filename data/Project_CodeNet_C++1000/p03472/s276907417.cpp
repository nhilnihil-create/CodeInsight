#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,H;
  cin>>N>>H;
  long long a[N];
  long long b[N];
  for (int i=0;i<N;i++){
    cin>>a[i]>>b[i];
  }
  sort(a,a+N);
  sort(b,b+N);
  long long maxa=a[N-1];
  long long td=0;
  long long cnt=0;
  for(int i=N-1;i>-1;i--){
    if(b[i]>maxa){
      td=td+b[i];
      cnt++;
      if(td>=H){
        cout<<cnt<<endl;
        return 0;
      }
    }
  }
  if((H-td)%maxa==0){
    cout<<cnt+(H-td)/maxa<<endl;
    return 0;
  }
  else cout<<cnt+(H-td)/maxa+1<<endl;
  return 0;
}
