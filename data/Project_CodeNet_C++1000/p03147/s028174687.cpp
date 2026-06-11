

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

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);
 }

 long long numbers[500005];

 /*

 int main(){

   long long n;   cin>>n;
vector<int>v(n);

for(int i=0;i<n;i++)
cin>>v[i];

 int ans=0;

  while(true)
 {
   if(*max_element(v.begin(),v.end()) == 0)
    break;

    int i=0;

    while(i<n)
   {
      if(v[i] == 0) i++;
      else {
        ans++;
         while(i<n && h[i] > 0)
        {
            h[i]--;
            i++; }
      }
    }

  }

   cout<<ans<<endl;

return 0;
 }
   */
 int main(){

 long long n;
 cin>>n;

   vector<int>v(n);

 for(int i=0;i<n;i++)
    cin>>v[i];

    long long ans=0;

 while(true){

    if(*max_element(v.begin(),v.end()) == 0) break;

  //if(max(v,v+n) == 0)

    int i=0;

    while(i<n){

     if(v[i] == 0) i++;
     else {
        ans++;
        while(i<n && v[i] > 0){
            v[i]--;
            i++;
        }
      }
    }

 }

 cout<<ans<<endl;

 return 0;
 }