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
    pair<pair<string,int>,int> pair[n];
    string s; int p;
    rep(i,n){
        cin>>s>>p;
        pair[i]=make_pair(make_pair(s,-p),i);//-1倍
    }
    sort(pair,pair+n);//辞書順かつ得点が高い順
    rep(i,n) cout<<pair[i].second+1<<endl;
}