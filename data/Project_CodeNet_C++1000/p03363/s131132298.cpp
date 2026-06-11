#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    
   int n;
   cin>>n;
   vector<ll> A(n);
   rep(i,n){
       cin>>A[i];
   }
   //累積和
   vector<ll> B(n+1);
   B[0]=0;
   for(int i=1;i<=n;i++){
       B[i]=A[i-1];
       B[i]+=B[i-1];
   }
   sort(B.begin(), B.end());
//    for(auto b:B){
//        cout<<b<<" ";
//    }
//    cout<<endl;
   vector<ll> ans;
   ll count=1;
   int i=1;
   while(i<=n){
       while(B[i]==B[i-1] && i<=n){
           count++;
           i++;
       } 
       ans.push_back(count);
       count=1;
       i++;
   }
//    for(auto an:ans){
//        cout<<an<<" ";
//    }
//    cout<<endl;
   ll res=0;
   rep(i, ans.size()){
       if(ans[i]%2==0){
           res+=(ans[i]/2)*(ans[i]-1);
       }else{
           res+=((ans[i]-1)/2)*ans[i];
       }
        // res+=ans[i]*(ans[i]-1)/2;
   }

    cout<<res<<endl;

    return 0;
}
