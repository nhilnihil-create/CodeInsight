#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;




int main() {

 int n;
 cin >> n;
 vector<int> d(n);
 rep(i,n){
     cin >> d.at(i);
 }
 sort(d.begin(),d.end());
 reverse(d.begin(),d.end());

 int care = 0;
 int ans = 0;
 rep(i,n){
    if(care != d.at(i)){//もしcareがdのi番と違うなら
        ans++;
        care = d.at(i);
    }else{
        care = d.at(i);
    }
 }
 cout << ans << endl;

}

