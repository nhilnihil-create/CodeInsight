#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    vector<pair<int,int>> vec(5);
    for(int i=0;i<5;i++){
        cin >> vec[i].second;
        vec[i].first = vec[i].second%10;
        if(vec[i].first == 0) vec[i].first = 10;
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    int ans = 0;
    for(int i=0;i<4;i++){
        vec[i].second = (vec[i].second+9)/10;
        ans += 10*vec[i].second;
    }
    ans += vec[4].second;

    cout << ans << endl;
}