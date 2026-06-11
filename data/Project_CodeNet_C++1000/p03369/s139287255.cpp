/*
      author : nishi5451
      created: 11.08.2020 20:17:43
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(auto a : s){
        if(a == 'o') ans++;
    }
    cout << 700+ans*100 << endl;
    return 0;
}