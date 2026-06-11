#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
//---------------------------------------------------
//????????????????????????????????????
#define int long long
#define str string
#define rep(i,j) for(int i=0;i<(int)(j);i++)
typedef long long ll;
typedef long double ld;
const ll inf = 4523372036854775807;
struct P {
    ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {//??£??\???????????¨???
    ll to, cost;
};
struct S {//???????????±?????\???????????°
    int from, to, cost;
};
struct H {
    int x, y;
};
ll gcd(ll i, ll j) {//?????§??¬?´???°
    if (i > j) swap(i, j);
    if (i == 0) return j;
    return gcd(j%i, i);
}
ld rad(ld a, ld b, ld c, ld d) {
    return sqrt(pow(a - c, 2) + pow(b - d, 2));
}//rad?????§?¨???????2??????????????¢
//---------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++
string a;
int b[3];
signed main(){
	cin>>a;
	for(int i=0;i<a.size();i++){
		b[(int)a[i]-'a']++;
	}
	int s=min(b[0],min(b[1],b[2]));
	b[0]-=s,b[1]-=s,b[2]-=s;
	if(b[0]<=1&&b[1]<=1&&b[2]<=1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
    getchar(); getchar();
}
