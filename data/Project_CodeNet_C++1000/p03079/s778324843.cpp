#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long int
#define  ull unsigned long long int
const  int MAX=1e5+9;
const  int MAX1=1e6+9;
const  double pi = acos(-1);
const  int inf =1e9;
const  long long  mod = 1e9+7;
bool prime[MAX];
int pfactors[MAX];
ll fact[MAX];
ll ifact[MAX];
ll mexp(ll a,ll b){ll res=1;while(b>0){if(b%2){res=(res*a);}a=(a*a);b=b/2;}return res;}
vector<int> totient(){
  long long tt[MAX];
    for(int i=1;i<MAX;i++) tt[i]=i;
    for(int i=2;i<MAX;i++){ if(tt[i]==i){for(int j=i;j<MAX;j+=i){  tt[j]/=i; tt[j]*=i-1;}}}
    vector<int>v;
    for(int i=1;i<MAX;i++)v.push_back(tt[i]);
    return v;
}
vector<int> seive(){
    for(int i=2;i<MAX;i++)prime[i]=false;
    int k=0;
  vector<int>p;
    for(int i =2;i<MAX;i++){if(!prime[i]){  for(int j=2*i;j<MAX;j+=i)  prime[j]=true;}}
      for(int i=2;i<MAX;i++){if(!prime[i])    p.push_back(i);}return p;} 
  int a[90];
int n;
set<int> v={1, 4, 9, 16 ,25 ,36 ,49 , 64 , 81};
int check(int a ,int b){
  int mask=(1<<10);
  vector<int>res;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(a&(1<<i)){
        if(b&(1<<j)){
        int p=i*10+j;
        int q=j*10+i;
        if(v.find(p)!=v.end()){
          res.push_back(p);
        }
        if(v.find(q)!=v.end()){
          res.push_back(q);
        }
      }

      }
    }
  }
 // cout<<res.size()<<"\n";
  res.erase(unique(res.begin(),res.end()),res.end());
  if(res.size()==9)
    return 1;
  else
    return 0;

}
bool check(int a, int b ,int c)
{
  return a==b&&a==c;
}
int main(){
   // ios_base::sync_with_stdio(false); 
   // cin.tie(NULL);    
  //freopen ("in.txt","r",stdin);
 // freopen ("out..txt","w",stdout);
  int a, b,c;
  cin>>a>>b>>c;
  if(check(a, b, c))
    cout<<"Yes";
  else
    cout<<"No";
}