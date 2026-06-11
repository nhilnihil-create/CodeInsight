#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    int min_x=1005;
    rep(i,s.size()-2){
        min_x=min(min_x,abs(753-(s[i]-'0')*100-(s[i+1]-'0')*10-(s[i+2]-'0')));
    }
    cout<<min_x<<endl;

    return 0;
}