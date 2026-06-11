#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n ;
    cin >> n ;
    vector<pair<pair<string,int>, int>> vec (n);
    rep(i, n){
        string s ;
        int p ;
        cin >> s >> p ;
        p = 100 - p ;
        pair<pair<string,int>, int> k (pair<string,int>(s, p), i) ;
        vec[i] = k ;
    }
    sort(vec.begin(), vec.end()) ;
    rep(i, n){
        cout << vec[i].second + 1  << endl ;
    }
} 