#include<vector>
#include<algorithm> // sort,reverse,min,lower_bound
#include<iostream>
using namespace std;
#define df 0
#define MAX_ORD 30
typedef long int li;
void fb(li a);
li solve(li a,vector<li>& b,int ord);
int dc=1000;

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >>n;
  vector<li> a(n),b(n);
  for(li& x: a) cin >>x;
  for(li& x: b) cin >>x;

  li s=0,mask=(1<<MAX_ORD)-1;
  for(int i=MAX_ORD-1;i>=0;i--,mask>>=1){
    for(li& x: b) x&=mask;
    sort(b.begin(),b.end());
    if(df){
      printf("b:");
      for(li& x: b){
	fb(x); cout << " ";
      }
    }
    li temp=0;
    for(int j=0;j<n;j++){
      temp ^= solve(a.at(j)&mask,b,i);
    }
    s^=temp;
  }
  cout << s;
}

void fb(li a){
  li mask=1<<MAX_ORD;
  while(mask){
    printf("%d",a&mask?1:0);
    mask/=2;
  }
}

li solve(li a,vector<li>& b,int ord){
  if(df) {
    printf("solve a:");
    fb(a);
    printf(", ord:%d\n",ord);
    fb((1<<(ord+1))-1);
    cout <<" ";
    fb(1<<ord);
    cout <<" ";
    fb((1<<(ord+2))-1);
    cout <<" ";
    fb((1<<ord)*3);
    cout <<"\n";
  }
  li count=upper_bound(b.begin(),b.end(),(1<<(ord+1))-1-a)-lower_bound(b.begin(),b.end(),(1<<ord)-a);
  count ^= upper_bound(b.begin(),b.end(),(1<<(ord+2))-1-a)-lower_bound(b.begin(),b.end(),(1<<ord)*3-a);
  if(df)printf("count %d\n",count);
  count %=2;
  return count<<ord;
}  

/// confirm df==0 ///
