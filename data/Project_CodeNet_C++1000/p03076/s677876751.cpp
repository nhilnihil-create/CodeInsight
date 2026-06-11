#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    vector<int> a(5);
    int ans = 0;
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        ans += ((tmp+10-1)/10)*10;
        tmp %= 10;
        a[i] = tmp;
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < 5; i++){
        if(a[i] != 0){
            ans -= 10-a[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}