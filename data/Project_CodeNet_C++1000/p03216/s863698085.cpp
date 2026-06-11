#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int k; cin >> k;
        int l = 0, r = 0;
        ll d = 0, m = 0, dm = 0, dmc = 0;
        while(r < n){
            if(r - l == k){
                l++;
                if(s[l-1] == 'D'){
                    dm -= m; d--;
                }
                else if(s[l-1] == 'M'){
                    m--;
                }
            }
            r++;
            if(s[r-1] == 'D'){
                d++;
            }
            else if(s[r-1] == 'M'){
                m++;
                dm += d;
            }
            else if(s[r-1] == 'C'){
                dmc += dm;
            }
        }
        cout << dmc << endl;
    }
    return 0;
}