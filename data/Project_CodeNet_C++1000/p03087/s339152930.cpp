#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> sub(n);
    sub[0] = 0;
    for(int i=1; i<(int)s.length(); ++i){
        if(s[i-1]=='A' && s[i]=='C'){
            sub[i] = 1+sub[i-1];
        }
        else
            sub[i] = sub[i-1];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << sub[r]-sub[l] << endl;
    }
}