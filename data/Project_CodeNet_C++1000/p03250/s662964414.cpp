#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> vec;
    for(int i = 0; i< 3; i++){
        int t; cin >> t; vec.pb(t);
    }
    sort(vec.begin(),vec.end());
    cout << vec[vec.size()-1]*10+vec[1]+vec[0] << endl;
    return 0;
}
