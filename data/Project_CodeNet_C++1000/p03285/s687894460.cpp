/*
      author  : nishi5451
      created : 14.08.2020 19:51:57
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(7*i+4*j==n){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
