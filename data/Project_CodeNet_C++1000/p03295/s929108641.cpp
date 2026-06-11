#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> war(m);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        war[i] = {b,a};
    }
    sort(war.begin(),war.end());
    int nowend = war[0].first;
    int ans = 1;
    for(int i = 0; i < m; i++){
        if(war[i].second >= nowend){
            ans++;
            nowend = war[i].first;
        }
    }
    cout << ans << endl;
}