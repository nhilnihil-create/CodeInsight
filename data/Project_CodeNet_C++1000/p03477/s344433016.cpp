/*
      author : nishi5451
      created: 11.08.2020 19:39:58
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = a+b-c-d;
    if(ans==0) cout << "Balanced" << endl;
    else if(ans>0) cout << "Left" << endl;
    else cout << "Right" << endl;
    return 0;
}