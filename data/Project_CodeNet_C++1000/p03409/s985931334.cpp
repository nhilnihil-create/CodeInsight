#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define vec_rep(itr,v) for(auto itr = v.begin(); itr != v.end(); ++itr)
#define ll long long

int main(void){
    int N;
    cin >> N;
    ll ans = 0; 
    vector<pair<int, int>> red, blue;
    int x,y;
    rep(i,N){
        cin >> x >> y;
        red.emplace_back(y, x);
    }
    rep(i,N){
        cin >> x >> y;
        blue.emplace_back(x, y);
    }
    sort(red.begin(), red.end(), greater<pair<int,int>>());
    sort(blue.begin(), blue.end());
    vec_rep(blue_itr,blue){
        pair<int, int> blue_point = *blue_itr;
        int blue_x = blue_point.first;
        int blue_y = blue_point.second;
        vec_rep(red_itr,red){
            pair<int, int> red_point = *red_itr;
            int red_x = red_point.second;
            int red_y = red_point.first;
            if(red_x >= blue_x || red_y >= blue_y)continue;
            ans++;
            red.erase(red_itr);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}