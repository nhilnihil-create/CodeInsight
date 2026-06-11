#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 1e18;
long long int mod = 1000000007;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "RULD";
//↓,→,↑,←

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll number1,ll number2){
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
    if(number1 > number2){
        swap(number1 , number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1 , number1);
    }
}


ll i,j,k,ii,jj;
ll n,m,w;
ll a,b,c,d,e,g,h,r;
ll l,ans,num;
ll x[800005],y[500005],z[500005];
bool dame,flag;
char s[500005],t[500005];
bool used[505][505];
ll dp[300][300];
ll kyo;

int main(){
    cin >> h >> w >> n;
	for(i=0;i<n;i++){
		cin >> a >> b;
		x[i] = 300000 * a + b;
	}
	for(i=n;i<h+n;i++){
		x[i] = 300000 * (i - n) + w + 1;
	}
	for(i=n+h;i<n+h+w;i++){
		x[i] = 300000 * (h + 1) + (i - n - h);
	}
	n = n + h + w;
	sort(x,x+n);
	a = 1;
	b = 1;
	while(1){
		//下に行けるか判定
		//pe(a);p(b);
		c = lb(x,x+n,(a+1)*300000+1+b) - lb(x,x+n,(a+1)*300000+1);
		if(c >= 1){
			break;
		}else{
			a++;
		}
		//右に動いてみる
		c = lb(x,x+n,a * 300000 + b + 2) - lb(x,x+n,a*300000+b+1);
		if(c == 0)b++;
	}
	p(a);




    return 0;
}