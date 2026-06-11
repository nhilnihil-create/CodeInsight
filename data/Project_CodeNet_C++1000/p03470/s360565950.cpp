/*
      author  : nishi5451
      created : 14.08.2020 16:47:16
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    set<int> li;
    int n;
    cin >> n;
    rep(i,n){
        int d;
        cin >> d;
        li.insert(d);
    }
    cout << li.size() << endl;
    return 0;
}