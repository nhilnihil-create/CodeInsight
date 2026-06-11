#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007


int res = 1000000;

void dfs(int amount,int count){

    if(amount == 0){
        chmin(res,count);
        return;
    }else{
        
        int money = 1;
        int tmp = amount;
        while(tmp >= 6){
            tmp /= 6;
            money*=6;
        }
        if(money> 1){
            dfs(amount-money,count+1);
        }

        money = 1;
        tmp = amount;
        while(tmp >= 9){
            tmp /= 9;
            money *=9;
        }
        if(money > 1){
            dfs(amount - money,count+1);
        }

        dfs(0,count+amount);
    }

}

int main(){

    int n;
    cin >> n;

    dfs(n,0);

    cout << res << endl;

    return 0;
}
