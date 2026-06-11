#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    vector<int> a(3);
    for(int i=0; i<3; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for(int i=1; i<3; i++){
        ans += abs(a[i] - a[i-1]);
    }
    cout << ans << endl;
    return 0;
}