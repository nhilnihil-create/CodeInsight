#include <bits/stdc++.h>
#include <string>

#define rep(i,n) for(i=0;i<(n);i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;

const ll MOD=1000000007ll;
const int MAX=5100000;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    for(int i=0;i<a;i++){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    for(int i=0;i<a;i++){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

ll fact[MAX], fact_inv[MAX];

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

// nCr
ll comb(ll n, ll r){
	ll t=1000000;
	fact[0]=1;
	    for(int i=0;i<t;i++){ fact[i+1]=fact[i]*(i+1)%MOD;}
	fact_inv[t]=power(fact[t], MOD-2);
	for(int i=0;i<t;i++){ fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;}
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
  
int main()
{
	cin.tie(0);	ios::sync_with_stdio(false);

  int i,j;
  int N,D,X; cin >> N >> D >> X;
  int A[N]; rep(i,N){cin >> A[i];}
  rep(i,N){
      for(j=1;j<=D;j+=A[i]){
          X++;
      }
  }
  cout << X << endl;

  return 0;
}
