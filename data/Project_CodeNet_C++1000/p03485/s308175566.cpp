/*
      author : nishi5451
      created: 11.08.2020 19:37:48
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    if((a+b)%2==0)
        cout << (a+b)/2 << endl;
    else cout << (a+b)/2 + 1 << endl;
    return 0;
}