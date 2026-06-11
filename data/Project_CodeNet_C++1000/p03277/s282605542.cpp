#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000],p[100000],t[100000];
int64_t ap;
int64_t inversions(int*s,int*e){
 if(e-s<=1)return 0;
 auto mid=s+(e-s>>1);
 int64_t rt=inversions(s,mid)+inversions(mid,e);
 int*tp=t;
 for(auto l=s,r=mid;l<mid||r<e;){
  if(l<mid&&r<e)*tp++=*l<=*r?(rt+=mid-l,*r++):*l++;
  else if(l<mid)*tp++=*l++;
  else *tp++=*r++;
 }
 copy(t,e-s+t,s);
 return rt;
}
int aux[200005];
long long count(int median)
{
 memset(aux,0,sizeof(aux));
 int sum = 0;
 long long res = 0;
 for(int i = 0; i <= n; ++i) {
  for(int j = n + sum; j >= 0; j -= ~j & j + 1) {
   res += aux[j];
  }
  for(int j = n + sum; j <= n + n; j += ~j & j + 1) {
   aux[j] ++;
  }
  if(i < n) {
   sum += (a[i] >= median ? 1 : -1);
  }
 }
 return res*2>=ap;
}
bool j(int m){
 m=b[m];
 for(int i=0;i<n;++i)p[i+1]=p[i]+(a[i]>=m?1:-1);
 int64_t iv=inversions(p,p+n+1);
 bool geq=iv<<1>=ap;
 return geq;
}
int main(int ac,char**av){
 if(ac>1){
  srand(random_device{}());
  n=rand()%10;
  for(int i=0;i<n;++i)a[i]=rand();
 } else{
  scanf("%d",&n);for(int i=0;i<n;++i)scanf("%d",a+i);
 }
 copy(a,a+n,b);
 sort(b,b+n);
 ap=n*int64_t(n+1)>>1;
 int high=n,low=0;
 while(high-low>1){
  int mid=high+low>>1;
  if(j(mid)!=count(b[mid])){
   for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;
   cerr<<"ERROR "<<b[mid]<<' '<<j(mid)<<' '<<count(mid)<<endl;
   throw;
  }
  (j(mid)?low:high)=mid;
 }
 printf("%d\n",b[low]);
}