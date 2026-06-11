#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int N;
    string s;
    cin >> N >> s;
    int red=0, blue=0;
    for(int i=0; i<N; i++){
        if(s[i]=='R') red++;
        else blue++;
    }
    if(red>blue) cout << "Yes";
    else cout << "No";
}