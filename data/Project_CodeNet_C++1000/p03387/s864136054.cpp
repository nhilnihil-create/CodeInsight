#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;
    int o1, o2, o3; // 大きい順に格納
    o1 = max(a, max(b, c));
    o3 = min(a, min(b, c));
    if((o1==a && o3==b) || (o3==a && o1==b)) o2 = c;
    if((o1==b && o3==c) || (o3==b && o1==c)) o2 = a;
    if((o1==a && o3==c) || (o3==a && o1==c)) o2 = b;

    int ans = 0;
    ans = o1-o2; o2 += ans; o3 += ans;  // 二番目に大きい数を一番目に大きい数に合わせる。
    if(o1%2 != o3%2){
        ans++; o1++; o2++;  // o1とo3の偶奇が異なったらo1とo2に1を足す
    }
    ans += (o1 - o3) / 2;  // o3をo1に合わせに行く

    cout << ans << endl;
    return 0;
}