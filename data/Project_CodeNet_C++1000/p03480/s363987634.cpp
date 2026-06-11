#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s; cin>>s;
    int n=s.size();
    if(n%2==0){
        int ans=n/2;
        char che=s[n/2];
        rep(i,n/2){
            if(s[n/2-i-1]==che && s[n/2+i]==che){
                ans++;
            }else break;
        }
        cout<<ans<<endl;
        return 0;
    }else{
        int ans=(n+1)/2;
        char che=s[n/2];
        rep(i,n/2){
            if(s[n/2-1-i]==che && s[n/2+1+i]==che){
                ans++;
            }else break;
        }
        cout<<ans<<endl;
        return 0;
    }
}