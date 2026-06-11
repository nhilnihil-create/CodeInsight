
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

 int maxtime(long long a){
    return (a+9)/10*10;
 }

int left_time(long long b){
  return maxtime(b)-b;
}

int main(){
  
  long long a,b,c,d,e;
  
  cin>>a>>b>>c>>d>>e;
  
  long long ans=0;
  
  ans += maxtime(a) + maxtime(b) + maxtime(c) + maxtime(d) + maxtime(e);
  
  ans -= max( {left_time(a),left_time(b),left_time(c),left_time(d),left_time(e)} );
  
  cout<<ans<<endl;
  
  return 0; 
}
