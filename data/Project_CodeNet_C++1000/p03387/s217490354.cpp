#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
vector<int> num(3);
int main(){
    rep(i, 3) cin >> num[i];
    sort(all(num));
    int cnt=0;

    while(num[1] < num[2]){
        num[0]++;
        num[1]++;
        cnt++;
    }
    if((num[2]-num[0])%2 == 1){
        num[2]++;
        num[1]++;
        cnt++;
    }
    while(num[0] < num[2]){
        num[0] += 2;
        cnt++;
    }
    out(cnt);
}