
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int main(){

 ll a,b,k;
 cin>>a>>b>>k;

 ll n = (b-a+1);

 if(n<= k){
    for(int i=a;i<=b;i++)
        cout<<i<<endl;
    return 0;
 }

 set<int>ans;

 for(ll i=a;i<a+k;i++) ans.insert(i);

 for(ll i=b-k+1;i<=b;i++) ans.insert(i);

 for(auto it = ans.begin();it!= ans.end();it++)
    cout<<*it<<endl;

 return 0;
}