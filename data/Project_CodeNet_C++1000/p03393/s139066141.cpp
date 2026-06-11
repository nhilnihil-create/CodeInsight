#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    string s,t="abcdefghijklmnopqrstuvwxyz";
    cin>>s;
    if(s.size()<26){
        int num[30]={0};
        rep(i,s.size()) num[s[i]-'a']++;
        int a,z=1;
        rep(i,26){
            if(z&&num[i]==0){
                a=i,z=0;
            }
        }
        cout<<s<<t[a]<<"\n";
        return 0;
    }
    int x=s[25]-'a';
    vec C;
    C.push_back(x);
    rep(i,25){
        if(x<s[24-i]-'a') x=s[24-i]-'a',C.push_back(x);
        else{
            int ans=26;
            for(auto j:C) if(j>s[24-i]-'a'&&ans>j) ans=j;
            rep(j,s.size()-i-2) cout<<s[j];
            cout<<t[ans]<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
}