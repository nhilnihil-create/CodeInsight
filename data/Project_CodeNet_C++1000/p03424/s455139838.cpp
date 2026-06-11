/*
      author  : nishi5451
      created : 14.08.2020 17:23:41
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    rep(i,n){
        char c;
        cin >> c;
        if(c=='Y'){
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
    return 0;
}