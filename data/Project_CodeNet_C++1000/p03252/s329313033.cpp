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

 string s,t;
 cin>>s>>t;

  int n = s.size();
  map<char,char>ms,mt;

  for(int i=0;i<n;i++){
    ms[s[i]]++;
    mt[t[i]]++;
  }

  if(ms.size() == mt.size()){

     for(int i=0;i<n;i++)
     {
        if(ms[s[i]] == mt[t[i]])
            continue;
        else {
            cout<<"No"<<endl;
            return 0;
           }
     }
       cout<<"Yes"<<endl;
       return 0;
  }

  cout<<"No"<<endl;

 return 0;
 }
