#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    double ans=0,a;
    string b;
    int n;
    cin >> n;
    rep(i,n){
        cin >> a >> b;
        if(b=="JPY") ans += a;
        else ans += a*380000;
    }
    cout << setprecision(10) <<ans << endl;
}