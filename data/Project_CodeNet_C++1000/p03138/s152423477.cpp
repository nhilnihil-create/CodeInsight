#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=3.14159265359;

bool DP[50]; // DP[2のhoge乗] = フラグを立てた方がいい数

int main() {
    ll N, K;
    cin>>N>>K;
    ll A[N];
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    ll two = 1;
    int index = 0;
    int flag;
    while(two <= K){
        flag = 0;
        for(int i=0;i<N;++i){
            if((A[i]&two)==0) flag++;
        }
        if(flag > N/2) DP[index] = true;
        index++;
        two *= 2;
    }
    index--;
    two /= 2;
    ll tmpans = 0;
    for(int i=index;i>=0;--i){
        if((DP[i]==true) & (K>=two)){
            tmpans += two;
            K -= two;
        }
        two /= 2;
    }
    ll ans = 0;
    for(int i=0;i<N;++i){
        ans += tmpans ^ A[i];
    }
    cout<<ans<<endl;
}

