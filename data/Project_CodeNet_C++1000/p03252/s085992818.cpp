#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(ll)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s,t;cin>>s>>t;
    map<char,int> mp1,mp2;
    rep(i,s.size()){
        mp1[s[i]]++;
        mp2[t[i]]++;
    }
    map<int,int> mp3,mp4;
    for(auto&p:mp1){
        mp3[p.second]++;
    }
    for(auto&p:mp2){
        mp4[p.second]++;
    }
    for(auto&p:mp3){
        if(p.second!=mp4[p.first]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
