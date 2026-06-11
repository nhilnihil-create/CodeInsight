#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

typedef pair<int,int> P;

int n,a[200010];
bool check(int x){
   vector<P> str;
   str.push_back({0,a[0]}); ll sum=a[0];
   rep(i,1,n){
      if(a[i-1]<a[i]){
         if(a[i]-a[i-1])str.push_back({0,a[i]-a[i-1]});
         sum=a[i]; continue;
      }
      while(1){
         P p=str.back(); str.pop_back();
         sum-=p.second;
         if(sum<a[i]){
            p.second=a[i]-sum;
            sum=a[i]; str.push_back(p);
            break;
         }
      }
      int save=0;
      while(1){
         P p=str.back(); str.pop_back();
         if(p.first==x-1)save+=p.second;
         else{
            p.second--; if(p.second)str.push_back(p);
            str.push_back({p.first+1,1});
            if(save)str.push_back({0,save}); break;
         }
         if(save==sum)return false;
      }
   } return true;
}

int main(){
   scanf("%d",&n); rep(i,0,n)scanf("%d",&a[i]);
   //ifstream in("input.txt"); in>>n; rep(i,0,n)in>>a[i];
   int lb=0,rb=1e6;
   while(rb-lb>1){
      int mid=(lb+rb)/2;
      if(check(mid))rb=mid; else lb=mid;
   }
   printf("%d\n",rb);
   return 0;
}
