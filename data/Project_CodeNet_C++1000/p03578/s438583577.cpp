#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
 int n,m;
 cin >> n ;
 vector<ll> d(n);
 rep(i,n)cin >>d[i];
 cin >> m;
 vector<ll> t(m);
 rep(i,m)cin >> t[i];

 if(n<m)cout << "NO" << endl;
 else{
     map<ll,int> cnt;
     rep(i,n){
         if(cnt.count(d[i]))cnt.at(d[i])++;
         else cnt[d[i]]=0;
     }
     bool a=true;
     rep(i,m){
         if(cnt.count(t[i]) && cnt.at(t[i])==0)cnt.erase(t[i]);
         else if(cnt.count(t[i])){
             cnt.at(t[i])--;
         }
         else{
             a=false;
             break;
         }
     }
     if(a)cout << "YES" << endl;
     else cout << "NO" << endl;
 }
} 
    