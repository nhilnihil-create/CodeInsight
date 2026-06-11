#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> //tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;

int main(){
 int n; cin >> n;
 int sum=0;
 int tmp=n;
 while(tmp>0){
   sum+=tmp%10;
   tmp/=10;
 }
 if(n%sum==0) cout << "Yes" << endl;
 else pr("No"); 
return 0;
}
