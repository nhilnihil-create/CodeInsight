#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> data(3);
    for(int i=0; i<data.size(); i++) cin >> data.at(i);
    sort(data.begin(), data.end());
    int ans = data.at(2)*10 + data.at(1) + data.at(0);
    cout << ans << endl;

}