
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

 long long n,m;
 cin>>n;
 int a[n];
 map<int,int>mp;


 for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++; }

    cin>>m;
 int b[m];
 for(int i=0;i<m;i++){
    cin>>b[i];
 }

 for(int i=0;i<m;i++)
 {
    if(mp[b[i]] > 0){
        mp[b[i]]--;
    }
    else {
        cout<<"NO"<<endl;
        return 0;
    }
 }

 cout<<"YES"<<endl;

return 0;
 }