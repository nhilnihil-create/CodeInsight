/*
      author : nishi5451
      created: 11.08.2020 21:03:15
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    for(auto a : s){
        if(a=='1') cout << 9;
        else cout << 1;
    }
    cout << endl;
    return 0;
}