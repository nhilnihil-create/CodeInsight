//#include    <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define N  500005
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define MOD 998244353
#define Mod 1e9 + 7
template<typename T> inline T max(T a,T b,T c){
    return max(a,max(b,c));
}
template<typename T> inline T min(T a,T b,T c){
    return min(a,min(b,c));
}
template<typename T> inline T max(T a,T b,T c,T d){
    return max(a,max(b,c,d));
}
template<typename T> inline T min(T a,T b,T c,T d){
    return min(a,min(b,c,d));
}
const int  dx[]={0,1,0,-1,0,1,-1,1,-1};
const int  dy[]={0,0,1,0,-1,1,-1,-1,1};
typedef long long ll;
using namespace std;
int main(){
   ll n,a,b;
   scanf("%lld",&n);
   for (int i=1;i<=n;i++){
    scanf("%lld%lld",&a,&b);
    ll t1=a*b;
    ll t2=sqrt(t1);
     if (t2*t2==t1){
         if (a==b) printf("%lld\n",t2*2-2);
         else printf("%lld\n",t2*2-3);
     }
     else if (t2*(t2+1)<t1) printf("%lld\n",t2*2-1);
     else printf("%lld\n",t2*2-2);
   }
   return 0;
}
