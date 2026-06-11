#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<char, char>> v(q);
    for(int i = 0; i < q;i++){
        cin >> v[i].first >> v[i].second;
    }
    int l, r;
    l = -1, r = n;
    while(l+1!=r){
        int m = (l + r) / 2;
        int pos = m;
        for(auto x : v) {
            if(x.first==s[pos]){
                if(x.second == 'L'){
                    pos--;
                }else {
                    pos++;
                }
                if(pos == -1){
                    l = m;
                    break;
                }
            }
        }
        if(l!=m){
            r = m;
        }
    }
    int left = l; // l文字目の位置までは絶対落ちる
    l = left, r = n;
    while(l+1!=r){
        int m = (l + r) / 2;
        int pos = m;
        for(auto x:v){
            if(x.first==s[pos]){
                if(x.second=='L'){
                    pos--;
                }else{
                    pos++;
                }
            }
            if(pos == n){
                r = m;
                break;
            }
        }
        if(r!=m){
            l = m;
        }
    }
    int right = r; // r文字目の位置は右に絶対落ちる
    //cout << right << endl;
    cout << max(0, n - (left + 1) - (n - right)) << endl;
    return 0;
}