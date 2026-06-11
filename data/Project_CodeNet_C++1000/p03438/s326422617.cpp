#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<long long> a(N),b(N);
  for(int i=0; i<N; i++) cin >> a[i];
  for(int i=0; i<N; i++) cin >> b[i];
  
  // sum(b)-sum(a) 回の試行
  long long total=0;
  for(int i=0; i<N; i++){
    total-=a[i];
    total+=b[i];
  }
  
  //最低限の試行回数
  vector<long long> u(N,0),v(N,0);
  for(int i=0; i<N; i++){
    if(a[i]<b[i]){
      long long k=b[i]-a[i];
      if(k%2==0){
        a[i]+=k;
        u[i]+=k/2;
      }else{
        a[i]+=k+1;
        u[i]+=(k+1)/2;
        b[i]+=1;
        v[i]+=1;
      }
    }else if(a[i]>b[i]){
      long long k=a[i]-b[i];
      b[i]+=k;
      v[i]+=k;
    }
  }
  
  //今のところa=b
  //uが多い-->bに差分u-vをばらまく-->同じだけ試行をしてa=bに戻せる
  //         最終試行回数はv+2(u-v)
  //vが多い-->aに差分v-uをばらまいても無理
  //同じ-->それが最終試行回数
  long long usum=0,vsum=0;
  for(int i=0; i<N; i++) usum+=u[i];
  for(int i=0; i<N; i++) vsum+=v[i];
  if(vsum>usum){
    cout << "No" << endl;
  }else{
    if(total==(2*usum-vsum)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}