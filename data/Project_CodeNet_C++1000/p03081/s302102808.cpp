#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<char>> td(q);
    for(auto& v:td){
        char t, d; cin >> t >> d;
        v = vector<char>{t, d};
    }
    // Left Survive
    int l = -1, r = n;
    while(r - l > 1){
        int middle = (l + r) / 2;
        int tm = middle;
        int ok = true;
        for(int i=0; i<q; i++){
            if(tm >= n){break;}
            if(td[i][0] == s[tm]){
                if(td[i][1] == 'L') tm--;
                else tm++;
            }
            if(tm < 0){
                ok = false;
                break;
            }
        }
        if(ok){
            r = middle;
        }
        else{
            l = middle;
        }
    }
    int left_survive = r;
    // Right Survive
    l = -1, r = n;
    while(r - l > 1){
        int middle = (l + r) / 2;
        int tm = middle;
        int ok = true;
        for(int i=0; i<q; i++){
            if(tm < 0){break;}
            if(td[i][0] == s[tm]){
                if(td[i][1] == 'L') tm--;
                else tm++;
            }
            if(tm >= n){
                ok = false;
                break;
            }
        }
        if(ok){
            l = middle;
        }
        else{
            r = middle;
        }
    }
    int right_survive = l;
    cout << right_survive - left_survive + 1 << endl;
    return 0;
}