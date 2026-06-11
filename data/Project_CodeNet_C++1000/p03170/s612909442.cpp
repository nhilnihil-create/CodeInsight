#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long int

ll mod=1e9+7;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> can_win(k+1,0);
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                if(can_win[i-a[j]]%2==0){
                    can_win[i]=can_win[i-a[j]]+1;
                    break;
                }
                else{
                    can_win[i]=can_win[i-a[j]]+1;
                }
            }
        }
    }
    if(can_win[k]%2!=0){
        cout<<"First\n";
    }
    else{
        cout<<"Second\n";
    }
    return 0;
}