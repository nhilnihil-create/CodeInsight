#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

const ll MOD = 1e+9+7;
const int INF = 1e+9+7;


void prime_fac(int num,vector<int> &ans){
	for(int i=2;i<=num;i++){
        while(num%i==0){
            ans[i]++;
            num/=i;
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> v(N+1,0); //素因数分解結果の格納先
    rep2(i,1,N+1){
        prime_fac(i,v);
    }
    
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    
    rep2(i,1,N+1){
        if(v[i]>=2) a++;
        if(v[i]>=4) b++;
        if(v[i]>=14) c++;
        if(v[i]>=24) d++;
        if(v[i]>=74) e++;
    }

    int ans=0;
    ans+=((a-2)*b*(b-1))/2;
    ans+=d*(a-1);
    ans+=c*(b-1);
    ans+=e;
    cout << ans <<endl;
}
