#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
//エラトステネスの篩
int prime[MAX];
bool is_prime[MAX+1];

void sieve(int n){
	int p=0;
	for(int i=0;i<=n;i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2;i*j<=n;j++)	is_prime[i*j]=false;
		}
	}
}
int main(){
    int n;
    cin>>n;
    sieve(55555);
    vector<int>ans(n);
    int i=0;
    int w=0;
    while(prime[i]){
        int t=prime[i]%5;
        if(t==1){
            ans[w++]=prime[i];
        }
        i++;
        if(w>=n)break;
    }
    REP(i,n)OUT(ans[i]);
    return 0;
}