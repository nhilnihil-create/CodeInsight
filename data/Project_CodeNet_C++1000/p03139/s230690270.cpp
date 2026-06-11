/*
      author : nishi5451
      created: 12.08.2020 14:59:12
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,a,b;
    cin >> n >> a >> b;
    cout << min(a,b) << " " << (a+b>n ? a+b-n : 0)<< endl;
    return 0;
}