#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec.at(i);
    }

    vector<int> vec2(n);
    int min=1000000000;
    int ans=0;
    for (int i = 0; i < n; i++){
        vec2.at(i) = abs(a*1000-(t*1000-vec.at(i)*6));
        if (vec2.at(i) < min){
            min = vec2.at(i);
            ans = i;
            // cout << min << endl;
            // cout << ans << endl;
            // cout << endl;
        }
    }
    
    cout << ans+1 << endl;
}