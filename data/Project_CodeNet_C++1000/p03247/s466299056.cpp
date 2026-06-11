#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

ll N,m,len,len_max;
v_ll X,Y;

int main(){
  cin >> N;
  X.assign(N+10,0);
  Y.assign(N+10,0);
  bool odd=true,even=true;
  for (ll i=1;i<=N;i++){
    cin >> X[i] >> Y[i];
    if ((X[i]+Y[i])%2==0)odd=false;
    else even=false;
  }
  if (!odd && !even){
    cout << -1 << endl;
    return 0;
  }
  len_max=(ll)1<<30;
  if (odd) m=31;
  else m=32;
  cout << m << endl;
  len=len_max;
  for (ll i=1;i<=m;i++){
    cout << len;
    if (i<m) cout << " ";
    len/=2;
    if (len<1)len=1;
  }
  cout << endl;
  for (ll i=1;i<=N;i++){
    len=len_max;
    ll x_t=X[i],y_t=Y[i];
    ll x_n=0,y_n=0;
    for (ll j=1;j<=m;j++){
      if (abs(x_t-x_n)>abs(y_t-y_n)){
        if (x_t-x_n<0) {cout<< "L";x_n-=len;}
        else {cout << "R";x_n+=len;}
      }else{
        if (y_t-y_n>0) {cout<< "U";y_n+=len;}
        else {cout << "D";y_n-=len;}
      }
      len/=2;
      if (len<1)len=1;
    }
    cout << endl;
  }

}
