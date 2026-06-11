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
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int cnt[100005]={0};
   int c[100005]={0};
   for(int i=0;i<n;i++){
     if(i%2==0){
      cnt[a[i]]++;
     }else{
      c[a[i]]++;
     }
   }
   int count=n/2;
   int maxcnt=0;
   for(int i=0;i<=100000;i++){
    if(cnt[i]>cnt[maxcnt]){
      maxcnt=i;
    }
   }
   int maxc=0;
   for(int i=0;i<=100000;i++){
    if(c[i]>c[maxc]){
      maxc=i;
    }
   }
   if(maxcnt==maxc){
    if(cnt[maxcnt]>cnt[maxc]){
      int l=0;
      for(int i=0;i<=100000;i++){
        if(i!=maxc){
          l=max(c[i],l);
        }
      }
      cout<<n/2-cnt[maxcnt]+n/2-l<<"\n";
    }
    if(cnt[maxcnt]==cnt[maxc]){
      int l=0;
      for(int i=0;i<=100000;i++){
        if(i!=maxc){
          l=max(c[i],l);
        }
      }
      int k=0;
      for(int i=0;i<=100000;i++){
        if(i!=maxcnt){
          k=max(cnt[i],k);
        }
      }
      cout<<min(n/2-cnt[maxcnt]+n/2-l,n/2-c[maxc]+n/2-k)<<"\n";
    }
    if(cnt[maxcnt]<cnt[maxc]){
      int k=0;
      for(int i=0;i<=100000;i++){
        if(i!=maxc){
          k=max(c[i],k);
        }
      }
      cout<<n/2-c[maxc]+n/2-k<<"\n";
    }

   }else{
       
       
       cout<<n/2-cnt[maxcnt]+n/2-c[maxc]<<"\n";
   }




}
