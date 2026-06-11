#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000003;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    if(n==3){
        cout<<2<<" "<<5<<" "<<63<<endl;
        return 0;
    }
    if(n==4){
         cout<<2<<" "<<5<<" "<<20<<" "<<63<<endl;
         return 0;
   }
   if(n==5){
       cout<<2<<" "<<5<<" "<<20<<" "<<30<<" "<<63<<endl;
         return 0;
   }
   set<int> s;
   ll sum=0;
   for(int i=0;i<n/4;i++){
       s.insert(6*i+2);
       s.insert(6*i+3);
       s.insert(6*i+4);
       s.insert(6*i+6);
       sum+=15;
   }
   int t=n/4;
       if(n%4==1){s.insert(6*t+2);sum+=2;}
       if(n%4==2){s.insert(6*t+2);s.insert(6*t+3);sum+=5;}
       if(n%4==3){s.insert(6*t+2);s.insert(6*t+3);s.insert(6*t+4);sum+=9;}
       if(sum%6==2){s.erase(8);s.insert(6*t+6);}
       if(sum%6==3){s.erase(9);s.insert(6*t+6);}
       if(sum%6==5){s.erase(9);s.insert(6*t+4);}
  for(auto ite=s.begin();ite!=s.end();ite++){
      cout<<*ite<<" ";
  }
  cout<<endl;
}