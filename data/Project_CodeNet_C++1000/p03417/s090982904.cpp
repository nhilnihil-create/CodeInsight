#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  ll n,m;
  cin>>n>>m;
  if(n==1){
            if(m==1){
              cout<<1<<endl;
            }
     		else if(m==2){
              cout<<0<<endl; 
            }
 			else{
              cout<<m-2<<endl;
            }
    }//n=1
   else if(n==2){
     cout<<0<<endl;
   }
  else{
    				if(m==1){
                      cout<<n-2<<endl; 
                    }
    				else if(m==2){
                      cout<<0<<endl;
                    }
    else{
      cout<<(n-2)*(m-2)<<endl; 
    }
  }
}