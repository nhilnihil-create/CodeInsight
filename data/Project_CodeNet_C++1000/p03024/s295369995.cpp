#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++ )
#define repf(i,m,n) for(int (i)=m;(i)<n;(i)++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define vec(name,num) vector<ll> name((num),0);
#define op(i) cout<<(i)<<endl;
#define ip(i) cin>>(i);
#define opN cout<<"No"<<endl;
#define opY cout<<"Yes"<<endl;
#define opP cout<<"Possible"<<endl;
#define opI cout<<"Impossible"<<endl;
#define mat(name,fnum,snum); vector<vector<ll>> name((fnum),vector<ll>((snum),0));
#define matC(name,fnum,snum); vector<vector<char>> name((fnum),vector<char>((snum),0));
#define debugP int debug_point; cin>>debug_point;
#define FI first
#define SE second
const ll MOD= 1e9 + 7;
template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
ll pow_mod(ll fi,ll se,ll mod){
  if(se==0){
    return 1;
  }
  if(se%2){
    return pow_mod(fi,se-1,mod)*fi%mod;
  }
  ll t=pow_mod(fi,se/2,mod);
  return t*t%mod;
}
template <class T>
vector<T> getv(ll n){
	vector<T> Vector_temp;
	rep(i,n){
		T input;
		cin >> input;
		Vector_temp.emplace_back(input);
	}
	return Vector_temp;
}
ll gcd(ll c,ll b){
    while(1){
        if(c%b!=0){
        ll tmp=b;
        b=c%b;
        c=tmp;
        }else{
            return b;
        }
    }
}

vector<pair<int,int>> Dir={{-1,0},{1,0},{0,1},{0,-1}};
/* <3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3*/


int main(){
  string s;
  cin>>s;
  ll ans=0;
  rep(i,s.size()){
    if(s[i]=='x')ans++;
  }
  if(ans>=8)op("NO")
  else op("YES")
  return 0;
}
