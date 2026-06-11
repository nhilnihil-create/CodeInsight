#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

int main() {
    string s=sin();
    ll count=0;
    ll ans=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s.at(i)=='A'){
            ans+=count;
        }
        else if(i>0){
            if(s.at(i)=='C'&&s.at(i-1)=='B'){
                count++;
                i--;
            }
            else{
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    cout<<ans<<endl;
}