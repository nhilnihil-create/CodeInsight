#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int n,m;
   cin >> n >> m;
    VI x(m);
    rep(i,m)cin >> x.at(i);
   if(n>=m)cout << 0 << endl;
   else{
    sort(x.begin(),x.end());
    ll dif=x.at(m-1)-x.at(0);
    VI y(m);
    rep(i,m-1){
        y.at(i)=x.at(i+1)-x.at(i);
    }
    sort(y.begin(),y.end());
    reverse(y.begin(),y.end());
    rep(i,n-1){
        dif-=y.at(i);
    }
    cout << dif << endl;
   }
}

