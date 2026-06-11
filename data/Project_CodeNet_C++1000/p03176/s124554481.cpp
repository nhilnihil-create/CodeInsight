#include<bits/stdc++.h>
using namespace std;
 long long tr[1000001]={0};
 void update(long long up,long long h,int idx,int s,int e){
   if(s>e)
   return;
   //cout<<s<<" "<<e<<" "<<idx<<" "<<h<<"\n";
   if(s==e){
      tr[idx]=up;
     //  cout<<s<<" "<<e<<" "<<idx<<" "<<h<<" leaf\n";
      return;
   }

   int mid=(s+e)/2;
   if(mid >= h){
     update(up,h,2*idx,s,mid);
   }else{
   update(up,h,2*idx+1,mid+1,e);
   }
   tr[idx]=max(tr[2*idx],tr[2*idx+1]);

 }
 long long getMx(int x,int idx,int s,int e){
        if(s>e || x<s){
        return INT_MIN;
        }

        if(e<=x)
        return tr[idx];
        int mid=(s+e)/2;

        long long m1=getMx(x,2*idx,s,mid);
        long long m2=getMx(x,2*idx+1,mid+1,e);
        return max(m1,m2);

 }
int main(){

long long n,m=0;
cin>>n;
long long h[n],a[n];
for(int i=0;i<n;i++)
  {cin>>h[i];
    m=max(m,h[i]);
  }
for(int i=0;i<n;i++)
 cin>>a[i];


 long long ans=0;
 for(int i=0;i<n;i++){

    long long  mx=getMx(h[i]-1,1,0,m);
  //cout<<h[i]-1<<" "<<mx<<" "<<a[i]<<"\n";
    ans=max(ans,mx+a[i]);
    update(mx+a[i],h[i],1,0,m);
 }

cout<<ans<<"\n";

}
