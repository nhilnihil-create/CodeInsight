#include <bits/stdc++.h>
using namespace std;

int padding(int n){
  int d=0;
  int m=n;
  while(m>0){
    m/=10;
    d++;
  }
  return 6-d;
}

int main(){
  long N,M;
  cin>>N>>M;
  vector<vector<long>> a(M,vector<long>(4));


  for(int i=0;i<M;i++){
    cin>>a[i][0]>>a[i][1];
    a[i][2]=i;
  }

  sort(a.begin(),a.end());
  vector<vector<long>> b(M,vector<long>(4));
  int idx=0;
  for(int p=1;p<=N;p++){
    int num=1;
    int c=0;
    while(idx<M&&p==a[idx][0]){
      a[idx][3]=num;
      num++;
      idx++;
      c++;

    }
  }

  for(int i=0;i<M;i++){
    b[i][0]=a[i][2];
    b[i][1]=a[i][0];
    b[i][2]=a[i][1];
    b[i][3]=a[i][3];
  }
  sort(b.begin(),b.end());

  for(int i=0;i<M;i++){
    int pad=padding(b[i][1]);
    for(int i=0;i<pad;i++) cout<<'0';
    cout<<b[i][1];
    pad=padding(b[i][3]);
    for(int i=0;i<pad;i++) cout<<'0';
    cout<<b[i][3]<<endl;

  }



}
