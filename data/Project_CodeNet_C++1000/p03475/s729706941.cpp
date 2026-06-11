#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> c(n-1), s(n-1), f(n-1);
    rep(i, n-1){
        cin >> c[i] >> s[i] >> f[i];
    }
    rep(i, n){
        lli t = 0;
        lli j = i;
        while(j < n){
            if(j < n-1){
                if(t < s[j]) t=s[j];
                else if(t%f[j] == 0);
                else t+=f[j]-t%f[j];
                t+=c[j];
            }
            j++;
        }
        cout << t << endl;
    }
    return 0;
}
