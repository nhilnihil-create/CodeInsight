//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>> 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>> 
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>

ld pie=3.141592653589793238462643383279;
int mod=1e9+7;

struct point{
  ld x,y;
};

vvi mat_mul(vvi mat1,vvi mat2){
  vvi ret;
  f(i,0,2){
    vi xx;
    f(j,0,2){
      int r=0;
      f(k,0,2) r=(r+(mat1[i][k]*mat2[k][j])%mod)%mod;
      xx.pb(r%mod);
    }
    ret.pb(xx);
  }
  return ret;
}

vvi mat_exp(vvi mat,int p){
  vvi iden={{1,0},{0,1}};
  while(p!=0){
    if(p&1) iden=mat_mul(iden,mat);
    p/=2; 
    mat=mat_mul(mat,mat);
  }
  return iden;
}


int myexp(int p){
  p++;
  int r=1;
  int val=2;
  while(p!=0){
    if(p&1){
      r*=val;
    }
    val*=val;
    p/=2;
  }
  r-=2;
  return r;
}


int fact[2000005];
int infact[2000005];
 
int inv(int a){
  int y=mod-2;
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r;
}
 
int po(int a,int y){
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r; 
}
 
void facto(){
  fact[0]=1;
  f(i,1,2000005) {fact[i]=i*fact[i-1]; fact[i]%=mod;}
  f(i,0,2000005) infact[i]=inv(fact[i]); 
}
 
int nck (int n,int k){
  if(k<0 || k>n) return 0;
  int ret=fact[n]; ret*=infact[k]; ret%=mod;
  ret*=infact[n-k]; ret%=mod;
  return ret;
}
  
void mymul(int arr[],int num){
  int carry=0;
  f(i,0,100){
    arr[i]=arr[i]*num+carry;
    carry=arr[i]/10;
    arr[i]%=10;
  }
}

map<int,int> mp;

int myfun(int val){
  auto it = mp.lower_bound(val);
  if(it==mp.begin()) return 0;
  --it; 
  return it->second;
}

void myerase(int val,int key){
 
}

int32_t main(){ 
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n; cin>>n;
  map<int,int> mp;
  f(i,0,n){
    int x; cin>>x;
    ++mp[x];
  }
  int del=0;
  for(auto it : mp){
    if(it.ss >= it.ff) del+=it.ss-it.ff;
    else del+=it.ss; 
  }
  cout<<del;
  return 0; 
}
// check for overflows dummy !!!