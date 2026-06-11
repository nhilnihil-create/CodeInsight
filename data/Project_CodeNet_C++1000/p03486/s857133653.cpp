#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;

void solve()
{
    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());
    if(s<t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}

int main(){
    int t;
    t=1;
    rep(i,t){
        solve();
    }
}