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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> a;
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        int temp=0;
        for(int j=0;j<k;j++){
            int pos;
            scanf("%d",&pos);
            pos--;
            temp=temp|(1<<pos);
        }
        a.push_back(temp);
    }
    debug(a);
    vector<int> parity(m);
    for(auto &x:parity)scanf("%d",&x);
    int cnt=0;
    for(int i=0;i<pow(2,n);i++){
        bool okay=true;
        for(int j=0;j<m;j++){
            int set_b=__builtin_popcount(a[j]&i);
            debug(i,j,a[j],set_b,parity[j]);
            if(set_b%2!=parity[j]%2){
                okay=false;
                break;
            }
        }
        if(okay){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
