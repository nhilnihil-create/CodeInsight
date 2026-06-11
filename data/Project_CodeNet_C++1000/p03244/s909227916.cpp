#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> odd(100010),even(100010);
    int v,maxo=0,maxe=0;
    rep(i,n){
        cin>>v;
        if(i%2==0) odd[v]++;
        else even[v]++;
    }
    int e=0,o=0;
    rep(i,100001){
        if(maxo<=odd[i]){
            maxo=odd[i];
            o=i;
        }
        if(maxe<=even[i]){
            maxe=even[i];
            e=i;
        }
    }
    if(e!=o) cout<<(n/2-maxo)+(n/2-maxe);
    else{
        int t=odd[o],tmpo=maxo,tmpe=maxe;
        maxo=0,maxe=0;
        odd[o]=0;//2番目に多いやつで奇数番書き換え
        rep(i,100001) 
            if(maxo<=odd[i]) maxo=odd[i];
        int ans1=(n/2-maxo)+(n/2-tmpe);
        maxo=0,maxe=0;
        odd[o]=t,even[e]=0;//2番目に多いやつで偶数番書き換え
        rep(i,100001)
            if(maxe<=even[i]) maxe=even[i];
        int ans2=(n/2-tmpo)+(n/2-maxe);
        cout<<min(ans1,ans2);
    }
}