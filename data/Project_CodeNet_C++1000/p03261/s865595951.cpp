#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<string> a(n);
    rep(i,n) cin>>a[i];
    char tmp=a[0][0];
    map<string,int> mp;
    rep(i,n){
        if(tmp!=a[i][0]||mp[a[i]]!=0){
            cout<<"No"<<endl;
            return 0;
        }
        mp[a[i]]++;
        tmp=a[i][a[i].size()-1];
    }
    cout<<"Yes"<<endl;
}