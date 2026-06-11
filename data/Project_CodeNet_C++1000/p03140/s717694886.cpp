#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    v.assign(n,vector<int>());
    rep(i,n) {
        rep(j,26) {
            v[i].push_back(0);
        }
    }
    string s1,s2,s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    rep(i,n) {
        v[i][s1[i]-97]++;
        v[i][s2[i]-97]++;
        v[i][s3[i]-97]++;
    }
    int ch=0;
    rep(i,n) {
        int mx=0;
        rep(j,26) {
            if (v[i][j] > mx) mx = v[i][j];
        }
        if (mx == 2) ch++;
        else if (mx==1) ch+=2;
    }
    cout << ch << '\n';
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}