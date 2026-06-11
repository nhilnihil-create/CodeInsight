#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll m[N],s[N];
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
   cin>>n>>k;
   for(int i=0;i<n;i++){
    cin>>m[i];
   }

  ll ans=((n-1)/(k-1));
  if((n-1)%(k-1)!=0)ans++;
cout<<ans;




    return 0;
}
