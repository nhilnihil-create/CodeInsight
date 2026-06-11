/*
      author  : nishi5451
      created : 15.08.2020 01:07:40
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<tuple<string,int,int>> a;
    for(int i=1; i<=n; i++){
        string s;
        int p;
        cin >> s >> p;
        p = -p;
        a.push_back(tie(s,p,i));
    }
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++){
        cout << get<2>(a[i]) << endl;
    }
    return 0;
}