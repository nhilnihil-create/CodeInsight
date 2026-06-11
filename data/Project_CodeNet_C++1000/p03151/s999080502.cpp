#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int N;
  cin>>N;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> d(N);
  int suma=0;
  for (int i=0;i<N;i++){
    cin>>a[i];
    suma=suma+a[i];
  }
  int sumb=0;
  for (int i=0;i<N;i++){
    cin>>b[i];
    sumb=sumb+b[i];
    d[i]=a[i]-b[i];
  }  
  if(suma<sumb){
    cout<<-1<<endl;
    return 0;
  }
  sort(d.begin(),d.end());
  int sumd=0;
  int count=0;
  while(d[count]<0){
    sumd=sumd+d[count];
    count++;
  }
  int j=0;
  while(sumd<0){
    sumd=sumd+d[N-1-j];
    j++;
  }
  cout<<count+j<<endl;
  
  return 0;
}

  