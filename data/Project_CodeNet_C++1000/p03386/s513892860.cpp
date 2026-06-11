/*
      author  : nishi5451
      created : 14.08.2020 18:01:49
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,k;
    cin >> a >> b >> k;
    if(2*k >= b-a+1){
        for(int i=a; i<=b; i++){
            cout << i << endl;
        }
        return 0;
    }
    for(int i=a; i<a+k; i++){
        cout << i << endl;
    }
    for(int i=b-k+1; i<=b; i++){
        cout << i << endl;
    }
    return 0;
}