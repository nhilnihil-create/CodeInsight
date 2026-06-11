
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

 ll n;
 cin>>n;
  vector<int>e(1e5+1),o(1e5+1);

  for(int i=0;i<n;i++){
     int x; cin>>x;
     if(i%2 == 0) o[x]++;
     else e[x]++;
  }

  int max_even = max_element(e.begin(),e.end())-e.begin();
  int max_odd = max_element(o.begin(),o.end())-o.begin();

  // if the max_even is equal to max_odd that means that the array elements are same hence
  // even dont want to have the array elements as same so
  // case1: e[max_even]-o[second_maxeven]
  // case2: o[max_even]-e[second_max_even]

  if(max_even != max_odd)
  {
        cout<<n-e[max_even]-o[max_odd]<<endl;
  }
 else {

   sort(e.rbegin(),e.rend());
   sort(o.rbegin(),o.rend());

   cout<<min(n-e[1]-o[0],n-e[0]-o[1])<<endl;

 }


 return 0;
 }
