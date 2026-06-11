/*
      author  : nishi5451
      created : 14.08.2020 21:59:27
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    if( (n/100)*111 >= n){
        cout << (n/100)*111 << endl;
        return 0;
    }
    else{
        cout << (n/100+1)*111 << endl;
    }
    return 0;
}