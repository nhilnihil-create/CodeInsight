#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}
 
int main() {
   int n,x;
   cin>>n>>x;
   vector<int> h(n+1);
   rep(i,n)cin>>h[i];
   h[n]=x;
   sort(h.begin(),h.end());
   vector<int> sa(n);
   rep(i,n)sa[i]=h[i+1]-h[i];
   if(n==1){
       cout<<sa[0]<<endl;
       return 0;
   }
   int ans=gcd(sa[0],sa[1]);
   for(int i=2;i<n;i++){
       ans=gcd(ans,sa[i]);
   }
   cout<<ans<<endl;

}