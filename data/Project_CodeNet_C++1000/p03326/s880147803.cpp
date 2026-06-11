#include <bits/stdc++.h>
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct three{
ll a,b,c;

};
ll n,m;
ll aans;
vector<three> our;
void fu(ll x,ll y ,ll z){
 //ll ans=0;
 vector<ll> v;
 for(auto kk:our){
  ll t=(x)*(kk.a)+(y)*(kk.b)+(z)*(kk.c);
   v.pb(t);

    }
    sort(all(v));
	reverse(all(v));
	ll tt=0;
	fo(i,m){
		tt+=v[i];

	}
	


aans=max(aans,tt);


}

int main(){

cin>>n>>m;
aans=0;

fo(i,n){
	three tmp;
	cin>>tmp.a>>tmp.b>>tmp.c;
	our.pb(tmp);


}
fu(1,1,1);
fu(1,1,-1);
fu(1,-1,1);
fu(1,-1,-1);
fu(-1,1,1);
fu(-1,1,-1);
fu(-1,-1,1);
fu(-1,-1,-1);
cout<<aans<<endl;


}
