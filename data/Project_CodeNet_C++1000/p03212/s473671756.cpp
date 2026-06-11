

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define inf    0x3f3f3f3f
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef vector<int>      vi;
typedef vector<bool>     vb;
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

 int cnt=0,cnt2=0;

bool check(int x, int n){

 set<int>st;

  while(x){
      st.insert(x%10);
      x /= 10;
  }

  if(st.size() == 3) return true;

      return false;
}

 void dfs(long long x,int n){

  // cout<<x<<" ? "<<n<<endl;
   if(n < x) return ;
   //cout<<x<<"  "<<n<<endl;
   if(check(x,n)) cnt++;

   dfs(10*x+3,n);
   dfs(10*x+5,n);
   dfs(10*x+7,n);

 }

 int main(){

 int n; cin>>n;
  dfs(0,n);
  cout<<cnt<<endl;

 return 0;
 }
