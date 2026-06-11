#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> like(m);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            a--;
            like[a]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
        if(like[i] == n)
            ans++;
    cout << ans << endl;
    return 0;
}