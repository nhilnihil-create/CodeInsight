#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


int main(){

     int n,k; cin>>n>>k;
    int a[n];
   map<int,int>mp;

    for(int i=0;i<n;i++){
        cin>>a[i];
      mp[a[i]]++; }

     priority_queue<int>Q;

  for(map<int,int>::iterator it = mp.begin();it!= mp.end();it++)
  {
     // cout<<it->second<<" "<<endl;
     Q.push(it->second);
  }

  int sum = 0;

  if(mp.size() < k)
  k = mp.size();

  for(int i=0;i<k;i++){
    sum += Q.top();
     Q.pop();
  }

  //cout<<n<<"  "<<sum<<endl;

  cout<<n-sum<<endl;

 return 0;
 }
