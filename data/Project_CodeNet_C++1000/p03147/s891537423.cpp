#include<bits/stdc++.h>

using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;


int main()
{
    int n;
    cin >> n;
    queue<vector<int> > qu;
    vector<int>v(n);
    for(auto &x: v) cin >> x;
    qu.push(v);
    int ans = 0;
    while(!qu.empty()){
        vector<int> u = qu.front();
        qu.pop();
        int mn = *min_element(u.begin(), u.end());
        ans += mn;
        vector<int> ne;
        for(int i=0; i<u.size(); i++){
            int fx = u[i]-mn;
            if(fx == 0){
                if(!ne.empty()){
                    qu.push(ne);
                }
                ne.clear();
            }
            else{
                ne.push_back(fx);
            }
        }
        if(!ne.empty()){
            qu.push(ne);
        }
    }
    cout << ans << "\n";

    return 0;
}
