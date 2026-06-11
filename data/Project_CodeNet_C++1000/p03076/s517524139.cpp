#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


   


int main() {
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  int t[5];
  
  t[0]=a%10;
  t[1]=b%10;
  t[2]=c%10;
  t[3]=d%10;
  t[4]=e%10;
  int mini=INF,cnt=0;
//cout << endl;
  rep (i,5){
   //cout << t[i] << endl;
    if (t[i]==0){

      cnt++;
    }
    else  mini=min(mini,t[i]);
  }
  if (mini>10) mini=0;
  a-=t[0];
  b-=t[1];
  c-=t[2];
  d-=t[3];
  e-=t[4];
//cout << cnt << endl;
if (cnt!=5)
cout << a+b+c+d+e+((5-cnt-1)*10)+mini << endl;
else cout << a+b+c+d+e+((5-cnt)*10)+mini << endl;
}

