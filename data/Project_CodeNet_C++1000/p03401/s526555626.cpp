
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+2);
    //aの[0]と[n+1]は0のままで1〜nまでに代入する
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    //sumは全てを回ったときの料金
    int sum=0;

    //0から始まって0に戻るのでループを0からn+1にしている
    for(int i=0; i<=n+1; i++){
        cin >> a[i];
        sum += abs(a[i]-a[i+1]);
    }

    for(int i=1; i<=n; i++){
        int dif = abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]);
        int ans = sum - dif;
        cout << ans << endl;
    }
    return 0;



}