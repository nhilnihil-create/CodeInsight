#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    string s;
    cin >> s;
    ll bcnt = 0;
    ll ans = 0;
    rep(i,0,s.size()){
        if(s[i]=='B'){
            bcnt++;
        }else{
            ans += bcnt;
        }
    }
    cout<<ans<<endl;
  return 0;
}