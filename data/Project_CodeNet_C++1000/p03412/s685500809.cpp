#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int> > b;
const int BIT = 30;
int n;

int main(){
    cin >> n;
    a.assign(n, 0);
    b.assign(BIT, vector<int>(n, 0));
    for(int i = 0; i < n;i ++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++){
        int tb;
        cin >> tb;
        for(int k = 0; k < BIT; k++){
            b[k][i] = (tb % (1 << (k + 1)));
        }
    }
    int ans = 0;
    for(int i = 0 ; i < BIT;i++){
        sort(b[i].begin(), b[i].end());
    }
    for(int i = 0;i < a.size(); i++){
        int crt;
        for(int k = 0; k < BIT; k++){
            int t = (1 << k);
            crt = a[i] % (1 << (k + 1));
            vector<int>::iterator left1 = lower_bound(b[k].begin(), b[k].end(), t - crt);
            vector<int>::iterator right1 = lower_bound(b[k].begin(), b[k].end(), 2 * t - crt);
            // right1 --;
            #ifdef DEBUG
            if (k <= 2){
                cout << "k = " << k << "\n";
            }
            #endif // DEBUG
            if(right1 >= left1){
                #ifdef DEBUG
                 if (k <= 2){
                    cout << "\tCase 1: " << left1 - b[k].begin() << " - " << right1 - b[k].begin() << "\n";
                    cout << "\t" << (*left1) << " " <<  t - crt <<  "\n";
                 }
                #endif // DEBUG
                ans ^= (((right1 - left1) & 1) ? 1 : 0) * (1 << k);
            }

            vector<int>::iterator left2 = lower_bound(b[k].begin(), b[k].end(), 3 * t - crt);
            vector<int>::iterator right2 = lower_bound(b[k].begin(), b[k].end(), 4 * t - crt);
            // right2 --;
            if(right2 >= left2){
                #ifdef DEBUG
                 if (k <= 2)
                cout << "\tCase 2: " << left2 - b[k].begin() << " - " << right2 - b[k].begin() << "\n";
                #endif // DEBUG
                ans ^= (((right2 - left2) & 1) ? 1 : 0) * (1 << k);
            }
        }
    }
    cout << ans;
}
