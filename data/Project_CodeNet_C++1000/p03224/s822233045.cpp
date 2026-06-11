#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)


int main(){
    int n;
    cin >> n;
    vector<int> yes;
    int v = 2;
    while(v*(v+1)/2<=n){
        yes.push_back(v*(v+1)/2);
        v++;
    }
    int exist = -1;
    for(int i = 0; i < yes.size(); i++){
        if(yes[i] == n){
            exist = i;
        }
    }
    if(n == 1){
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    if(exist == -1){
        cout << "No" << endl;
        return 0;
    }

    exist += 2;
    vector<vector<int>> ans(exist+1,vector<int>(exist,0));
    int num = 1;
    for(int cur = 0; cur < exist; cur++){
        for(int i = 0; i < exist - cur; i++){
            ans[cur][cur+i] = num;
            ans[cur+1+i][cur] = num;
            num++;
        }
    }
    cout << "Yes" << endl;
    cout << exist+1 << endl;
    for(int i = 0; i < exist+1; i++){
        cout << exist << " ";
        for(int j = 0; j < exist-1; j++){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][exist-1] << endl;
    }

    return 0;
}
