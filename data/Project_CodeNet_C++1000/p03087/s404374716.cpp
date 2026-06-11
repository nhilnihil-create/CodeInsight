#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n, q;
    string s;
    cin >> n >> q >> s;
    int freq[s.size() + 5] = {};
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'C' && s[i - 1] == 'A') freq[i] = freq[i - 1] + 1;
        else freq[i] = freq[i - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(l == 0) cout << freq[r] << endl;
        else cout << freq[r] - freq[l] << endl;
    }
    return 0;
}
