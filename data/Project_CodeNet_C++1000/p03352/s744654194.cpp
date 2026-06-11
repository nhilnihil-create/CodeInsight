#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int x; cin >> x;
    vector<int> check(x+1);
    check[1] = 1;
    for(int b = 2; b <= x; b++){
        int tmp = b*b;
        while(tmp <= x){
            check[tmp] = 1;
            tmp *= b;
        }
    }
    for(int i = x; i >= 1; --i){
        if(check[i]) {
            cout << i << endl;
            return 0;
        }
    }
}