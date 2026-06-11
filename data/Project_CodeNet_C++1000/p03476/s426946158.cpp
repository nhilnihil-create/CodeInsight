#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
    vector<int> a(10e5+10,1);
    a[0] = 0; a[1] = 0;
    rep(i,2,10e5+5){
        if (a[i]==1){
            for(int j=i*2;j<10e5+5;j+=i){
                a[j] = 0;
            }
        }
    }
    vector<int> b(10e5+10,0);
    rep(i,0,10e5+5){
        if (i%2==1 && a[i]==1 && a[(i+1)/2]==1){
            b[i+1] = b[i] + 1;
        }else{
            b[i+1] = b[i];
        }
    }
    int q;cin>>q;
    vector<int> ans;
    rep(i,0,q){
        int l,r;cin>>l>>r;
        ans.push_back(b[r+1]-b[l]);
    }
    for (auto x:ans){
        cout<<x<<endl;
    }
}