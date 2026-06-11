#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> s1 >> s2;
    if(s1[0] > s2[0]) cout << '>' << endl;
    else if(s1[0] == s2[0]) cout << '=' << endl;
    else cout << "<" << endl;
}