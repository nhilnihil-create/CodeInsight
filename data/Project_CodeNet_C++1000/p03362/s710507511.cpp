#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int prime[55556] = {};

int main(){
    int i, j, n;
    vector<int> res;
    cin >> n;
    for(i=2; i<55556; i++){
        if(prime[i] == 0){
            if(i%5 == 1){
                res.push_back(i);
            }
            j = 2;
            while(i*j<55556){
                prime[i*j] = 1;
                j++;
            }
        }
    }
    for(i=0; i<n; i++){
        cout << res[i] << ' ';
    }
    return 0;
}