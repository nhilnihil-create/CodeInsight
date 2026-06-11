#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<tuple<string,int,int>> restaurant(n);
    for(int i=0; i<n; i++){
        cin >> get<0>(restaurant[i]) >> get<1>(restaurant[i]);
        get<1>(restaurant[i])*=-1;
        get<2>(restaurant[i])=i+1;
    }

    sort(restaurant.begin(),restaurant.end());

    for(int i=0; i<n; i++){
        cout << get<2>(restaurant[i]) << endl;
    }
}