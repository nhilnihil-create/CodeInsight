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
    for(int i = n; i <= 999; ++i){
        int t = i;
        int a = t % 10;
        t /= 10;
        int b = t % 10;
        t /= 10;
        int c = t;
        if(a == b && b == c) {
            cout << i << endl;
            return 0;
        }
    }
}