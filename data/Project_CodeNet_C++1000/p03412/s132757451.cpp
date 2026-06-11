#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

inline int power(int x, int n){
  int ans=1;
  while(n>=1){
    if(n%2==1){ans*=x;}
    x*=x;
    n/=2;
  }
  return ans;
}

inline int get_numbers(int x, int a, vi& B){
  int ans=0;
  ans-=lower_bound(B.begin(), B.end(), x-a)-B.begin();
  ans+=lower_bound(B.begin(), B.end(), 2*x-a)-B.begin();
  ans-=lower_bound(B.begin(), B.end(), 3*x-a)-B.begin();
  ans+=lower_bound(B.begin(), B.end(), 4*x-a)-B.begin();
  return ans;
}

int main(){
  int N;cin>>N;
  vi A,B;
  vi power_table(30);
  for (int k=0;k<30;++k){
    power_table[k]=power(2, k);
  }
  for (int i=0;i<N;++i){
    int a;cin>>a;
    A.push_back(a);
  }
  for (int i=0;i<N;++i){
    int b;cin>>b;
    B.push_back(b);
  }

  vi Ak[29], Bk[29];
  for (int k=0;k<29;++k){
    for (int i=0;i<N;++i){
      Ak[k].push_back(A[i]%power_table[k+1]);
      Bk[k].push_back(B[i]%power_table[k+1]);
    }
  }

  vi sgn_table(29);
  for (int k=0;k<29;++k){
    sort(Bk[k].begin(), Bk[k].end());
    for (int i=0;i<N;++i){
      int a=Ak[k][i];
      int x=power_table[k];
      int num=get_numbers(x, a, Bk[k]);
      sgn_table[k]+=((num)%2);
    }
  }

  int ans=0;
  for (int k=0;k<29;++k){
    if (sgn_table[k]%2==1){ans+=power_table[k];}
  }
  cout << ans << endl;
  return 0;
}