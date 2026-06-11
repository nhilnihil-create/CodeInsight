#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n;
    string s[n];
    rep(i,n)cin>>s[i];
    cin>>m;
    string t[m];
    rep(i,m)cin>>t[i];
    
    map<string,int>a;
    rep(i,n){
        a[s[i]]++;
    }
    rep(i,m){
        a[t[i]]--;
    }
    int maxi=0;
    rep(i,n)maxi=max(a[s[i]],maxi);
    cout<<maxi<<endl;
    return 0;
}