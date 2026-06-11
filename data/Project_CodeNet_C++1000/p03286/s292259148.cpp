#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    string s = "";
    while(n){
        int r = n % 2;
        if(r < 0) r += 2;
        n = (n-r)/(-2); 
        s += r + '0';
    }
    reverse(ALL(s));
    if(s == "") s = "0";
    cout << s << endl;
}