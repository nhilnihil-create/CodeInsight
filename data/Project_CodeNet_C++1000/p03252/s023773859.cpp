
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

 int main(){

 string a,b;
 cin>>a>>b;

  map<char,int>mp;
  map<char,int>ani;

  for(int i=0;i<a.length();i++){
    mp[a[i]]++;
  }

  for(int j=0;j<b.length();j++){
   ani[b[j]]++;
  }

  for(int j=0;j<a.length();j++)
 {
    if(mp[a[j]] == ani[b[j]] )
     continue;
    else{
        cout<<"No"<<endl;
        return 0;
    }
 }

 cout<<"Yes"<<endl;

  return 0;
 }