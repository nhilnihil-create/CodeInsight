#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main(){cout<<fixed<<setprecision(10);
		   ll n;
           cin>>n;
           ll A=1,B=1,C=1;
           if(n%2==0){
            A=B=n;
             C=n/2;
           }
           else{
             //a,b固定
             /*
             4abc=n(ab+bc+ca)
             (4ab-nb-na)c=nab
             c=nab/(4ab-na-nb);
             */
             for(int a=1;a<=3500;a++){
               for(int b=a;b<=3500;b++){
              // if(a==3&&b==2)cout<<(n*a*b)%(4*a*b-n*a-n*b)<<endl;
                if((4*a*b-n*a-n*b)>0&&(n*a*b)%(4*a*b-n*a-n*b)==0){
                 C= (n*a*b)/(4*a*b-n*a-n*b);
                  A=a;
                  B=b;
                  cout<<A<<" "<<B<<" "<<C<<endl;
                  return 0;
                }
               }
             }
           }
           cout<<A<<" "<<B<<" "<<C<<endl;
           
}

