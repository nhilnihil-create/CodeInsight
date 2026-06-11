#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    vector<bool> seen(n);
    for(int i = 0; i < n; i++)cin >> p[i];
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == j || j == k || k == i)continue;
                if(seen[i] || seen[j] || seen[k]) continue;
                if(p[i] <= a && p[j] > a && p[j] <= b && p[k] > b){
                seen[i] = true;
                seen[j] = true;
                seen[k] = true;
                ans++;
                }
            }
        }
    }
    cout << ans << endl;

}