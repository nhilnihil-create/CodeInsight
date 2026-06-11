/*
      author  : nishi5451
      created : 14.08.2020 17:19:44
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    int Alice=0,Bob=0;
    for(int i=0; i<n; i++){
        if(i%2) Bob+=a[i];
        else Alice+=a[i];
    }
    cout << Alice-Bob << endl;
    return 0;
}