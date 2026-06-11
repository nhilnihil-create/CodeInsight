#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mae = 0;
    int ato = 0;
    int sw = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1){
            sw = 1;
        }
        if(sw == 0){
            mae++;
        }
        else{
            ato++;
        }
    }
    ato--;

    int ans = 100000000;
    for(int i=0; i<=k-1; i++){
        int tmp_ans;
        tmp_ans += (mae-i)/(k-1);
        if((mae-i)%(k-1) != 0) tmp_ans++;
        tmp_ans += (ato - (k-i-1))/(k-1);
        if((ato - (k-i-1))%(k-1) != 0) tmp_ans++;
        ans = min(tmp_ans, ans);
    }
    cout << ans+1 << endl;
    return 0;
}