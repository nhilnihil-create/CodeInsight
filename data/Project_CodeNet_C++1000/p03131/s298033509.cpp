
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

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

int main(){

    ll k,a,b;
    cin>>k>>a>>b;

    if(b-a <= 1)
      cout<<k+1<<endl;
    else{

       if(k<=a ) cout<<k+1<<endl;
      else {
      k -= (a-1);
      if(k%2) cout<<a+(b-a) * (k/2)+1<<endl;
      else cout<<a+(b-a)*(k/2)<<endl;
    }

    }

return 0;
}