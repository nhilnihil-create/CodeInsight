#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;


int main(){
    int s;
    cin >> s;
    for(int i = 1; ;i++){
        if(s == 2 || s == 1 || s == 4) {
            cout << i + 3 << endl;
            return 0;
        }
        if(s % 2 == 0) s = s/2;
        else s = s * 3 + 1;
    }
}