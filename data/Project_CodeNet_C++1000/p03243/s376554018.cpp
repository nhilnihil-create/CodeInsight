#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
 

 int main(){
     int n;
     cin>>n;
     rep(i,999){
         int a=n/100, b=n/10, c=n%10;
         b%=10;
         if(a==b && b==c) break;
         n++;
     }
     cout<<n<<endl;
 }