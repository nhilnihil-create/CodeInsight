#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int d; cin >> d;
    if(d == 25) cout << "Christmas" << endl;
    else if(d == 24) cout << "Christmas Eve" << endl;
    else if(d == 23) cout << "Christmas Eve Eve" << endl;
    else cout << "Christmas Eve Eve Eve" << endl;
}