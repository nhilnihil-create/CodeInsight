#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define fi first
#define se second
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    fio;
    string s;   cin>>s;
    ll sum=0;
    vector<int> v;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B'){
            v.push_back(i);
        }
    }
    reverse(v.begin(),v.end());
    int size=s.length()-1;
    for(int i=0;i<v.size();i++){
        sum+=(size-v[i]);
        size-=1;
    }
    cout<<sum<<'\n';
    return 0;
}