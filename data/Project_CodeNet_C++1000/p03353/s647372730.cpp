#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    int k;cin>>k;
    vector<string> tt;
    for(int i=0;i<s.size();i++){
        for(int j=1; j<=k && i+j<=s.size();j++){
            string t = s.substr(i, j);
            tt.push_back(t);
        }
    }
    sort(tt.begin(), tt.end());
    tt.erase(unique(tt.begin(), tt.end()), tt.end());
    cout<<tt[k-1]<<endl;
}