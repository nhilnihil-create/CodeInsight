/*
      author  : nishi5451
      created : 14.08.2020 19:12:59
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    int dif = b-a;
    int hb = dif*(dif+1)/2;
    cout << hb-b << endl;    
    return 0;
}