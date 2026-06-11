#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    vector<int>vec(3);
    cin >> vec[0];
    cin >> vec[1];
    cin >> vec[2];
    sort(vec.begin(),vec.end());
    if(vec[2]-vec[0]%2 == vec[2]-vec[1]%2) {
        cout << (vec[2]-vec[1]+vec[2]-vec[0])/2 << endl;
    }
    else {
        cout << 1+(vec[2]-vec[1]+vec[2]-vec[0]+1)/2 << endl;
    }
}

