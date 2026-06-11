#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<string> t;
    for(int i = 0;i<s.size();i++) {
        for(int j = 1;j<=k;j++) {
            string tmp = s.substr(i,j);
            t.push_back(tmp);
        }
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    cout << t[k-1] << endl;
}