#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const int MAX = 60606;
vector<bool> p(MAX, true);
int n;

int main(){
    cin >> n;
    p[0] = p[1] = false;
    for(int i = 2; i < MAX; i++){
        for(int j = i + i; j < MAX; j += i){
            p[j] = false;
        }
    }

    vector<int> sosu(0);
    rep(i, MAX){
        if(i % 5 == 1 && p[i]){
            sosu.emplace_back(i);
        }
    }
    rep(i, n) cout << sosu[i] << ((i == n - 1)? "\n" : " ");
    
    //judge
    /*
    for(int i = 0; i < n - 4; i++){
        for(int j = i + 1; j < n - 3; j++){
            for(int k = j + 1; k < n - 2; k++){
                for(int l = k + 1; l < n - 1; l++){
                    for(int m = l + 1; m < n; m++){
                        if((sosu[i] + sosu[j] + sosu[k] + sosu[l] + sosu[m]) % 5 != 0){
                            cout << "WA" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "AC" << endl;
    */

    return 0;
}