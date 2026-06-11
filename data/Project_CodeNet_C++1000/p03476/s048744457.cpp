#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}



int main() {
   fast();
   long long int N=100000;
   vector<long long int> prime(N+1);
   for(long long int i=0;i<=N;i++){
       prime[i]=1;
   }
   
   prime[0]=0;
   prime[1]=0;
   for(long long int i=2;i<=N;i++){
    if(prime[i]){
      for(long long int j=i*i;j<=N;j+=i){
        prime[j]=0;
      }
    }
   }
   int odd[N+1];
   for(int i=0;i<=N;i++){
    if(prime[i] && prime[(i+1)/2]){
      odd[i]=1;
    }else{
      odd[i]=0;
    }
   }
   //cout<<prime[3]<<"\n";
   for(int i=1;i<=N;i++){
    odd[i]+=odd[i-1];
   }
   int q;
   cin>>q;
   while(q--){
    int l,r;
    cin>>l>>r;
    cout<<odd[r]-odd[l-1]<<"\n";
   }

}
