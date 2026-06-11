#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int sn = s.size();
    vector<int> a(sn, 0), sum(sn, 0);
    for(int i=0; i+1<sn; ++i){
        if(s[i]=='A' && s[i+1]=='C'){a[i]++;}
    }
  	//for(int i=0; i<sn; ++i){cout << a[i] << ",";} cout << endl;
    for(int i=0; i+1<sn; ++i){
        sum[i+1] = sum[i] + a[i];
    }
    for(int i=0; i<q; ++i){
        int l, r; cin >> l >> r; l--; r--;
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}