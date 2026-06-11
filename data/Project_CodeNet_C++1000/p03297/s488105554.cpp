#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed

 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using vi =vc<int>;
long gcd(long a,long b){
    if( b==0) return a; 
    else return gcd(b,a%b);
} 

int fact(int n){
  if(n == 0) return 1;
  return fact(n -1);

}
int main(){
    int t;
    cin >> t;
    long a,b,c,d;
    long g;
    rep(i,t){
        cin >> a >> b >> c >> d;
        g = gcd(b,d);
            if(b>a){
                puts("No");
            }else if(b>d){
               puts("No"); 
            }else if(c>=b){
                puts("Yes");

            }else if((b-g+(a%g))>c){
                puts("No");
               }else{
                   puts("Yes");
               }

    }
}