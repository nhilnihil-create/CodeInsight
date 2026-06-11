


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
  ll d,n;
  cin >> d >> n;

  ll counts = 0;
  ll i = 0;

  while(true){

  i++;
  ll k=0;
  ll copys = i;

  while(copys%100 == 0){
      k++;
      copys /= 100;
  }

   if(k ==d) counts++;

   if(counts == n){
      cout<<i<<endl;
      return 0;
   }

  }

 return 0;
}
