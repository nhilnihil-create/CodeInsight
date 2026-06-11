#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(),v.end(),greater<int>());

    cout << v[0] * 10 + v[1] + v[2]<< endl;

}