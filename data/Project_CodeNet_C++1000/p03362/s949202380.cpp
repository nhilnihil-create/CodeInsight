#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

bool is_prime(int n){
  if (n==1) return false;
  if (n==2) return true; 
  for (int i=2;i<=(int)sqrt(n);i++){
    if (n%i==0) return false;
  }
  return true;
}

int main(){
  int N; cin >> N;
  vector<int> p;

  int i = 2,cnt=0;
  while(cnt<N){
    if (is_prime(i) && i%5==2){
      p.push_back(i);
      cnt++;
    }
    i++;
  }

  rep(i,N) {
    cout << p[i];
    if (i!=N-1) cout << " ";
  }
  cout << endl;




  return 0;
}