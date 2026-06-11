#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int series_sum(long long int);

int main(){
    int n,mid1,mid2;
    cin>>n;
    vector<int> vec(n),vec2(n);
    rep(i,n){
        cin>>vec[i];
        vec2[i]=vec[i];
    }
    sort(rall(vec2));
    mid1=vec2[n/2-1];
    mid2=vec2[n/2];
    rep(i,n){
        if(vec[i]<=mid2)cout<<mid1<<endl;
        else cout<<mid2<<endl;
    }
}