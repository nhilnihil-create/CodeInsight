
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

 int64_t n,i,j,k,ans=0;
  vector<int64_t>z(5);
  cin>>n;

  string s;

  for(i=0;i<n;i++){

   cin>>s;
   if(s.at(0) == 'M') z.at(0)++;
   else if(s.at(0) == 'A') z.at(1)++;
   else if(s.at(0) == 'R') z.at(2)++;
   else if(s.at(0) == 'C') z.at(3)++;
   else if(s.at(0) == 'H') z.at(4)++;
  }



  for(i=0;i<3;i++){
      for(j= i+1;j<4;j++){
            for(k=j+1;k<5;k++){

             // cout<<i+1<<j+1<<k+1<<"  "<<char(z.at(i))<<z.at(j)<<z.at(k)<<endl;

                  ans += z.at(i)*z.at(j)*z.at(k);
            }
      }
  }

  cout<<ans<<endl;

 return 0;
 }
