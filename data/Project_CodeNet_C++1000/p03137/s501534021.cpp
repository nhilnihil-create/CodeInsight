#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++) cin >> x[i];
    priority_queue<pair<int,int>> q;
    sort(x.begin(),x.end());
    for(int i = 0; i < m-1; i++){
        q.push({x[i+1]-x[i],i});
    }    
    vector<int> pin;
    pin.push_back(m-1);
    for(int i = 0; i < n-1; i++){
        if(q.empty()) break;
        pin.push_back(q.top().second);
        q.pop();
    }
    sort(pin.begin(),pin.end());
    int j = 0;
    int now = x[0];
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(i == pin[j]){
            ans += x[i]-now;
            if(i != m-1)now = x[i+1];
            j++;
        }
    }
    cout << ans << endl;
    return 0;

}