#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,d,x;
  cin >> n >> d >> x;
  rep(i,n){
    int a;
    cin >> a;
 	x += 1 +(d-1)/a;    
  }
  cout << x << endl;


  
  
  return 0;
    

}
