

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int  main(){

  string s;   cin>>s;
  int k; cin>>k;
  vector<string>v;

  int n = s.length();
 for(int i=0;i<n;i++){
      for(int j=1;j<=n-i;j++){
             if(j > k) break;
             string ans = s.substr(i,j);
                  v.push_back(ans); }

 }


 sort(v.begin(),v.end());
 unique(v.begin(),v.end());

 cout<<v[k-1]<<endl;

 return 0;
 }