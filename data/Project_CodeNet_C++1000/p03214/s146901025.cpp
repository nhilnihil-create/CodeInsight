#include<bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()
 
int GCD(int a,int b){ return b ? GCD(b,a%b) : a ;}
int LCM(int a,int b){ return a*b / GCD(a,b) ;}
 
typedef long long ll;
typedef unsigned long long ull;
 
const int INF = 1e9;

int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      int sum = 0;
      rep(i,n){
            cin >> a[i];
            sum += a[i];
      }
      int ans = -1;
      int Min = INF;
      for(int i=0;i<n;i++){
            if(abs(a[i]*n - sum) < Min){
                  Min = abs(a[i]*n - sum);
                  ans = i;
            }            
      }
      cout << ans << endl;

      return 0;
}
