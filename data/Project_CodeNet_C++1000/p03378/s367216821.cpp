#include<bits/stdc++.h>
using namespace std;

long long inputs[200005];
long long oddsum[200005];
long long evensum[200005];

int main(){
   int n,m,x;
   cin >> n >> m >> x;
   map<int,int>mp;
   for(int i=0; i<m; i++)
   {
       int a;
       cin >> a;
       mp[a]++;
   }
   int an1 = 0 , an2 = 0 ;

   for(int i=x; i<=n; i++)
   {
       an1 += mp[i];
   }for(int i=x; i>=0; i--)
   {
       an2 += mp[i];
   }

   cout << (min(an1,an2)) << endl;

}
