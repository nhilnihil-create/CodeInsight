#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main(){
    int n; cin >> n;
    vector<string> field(n);
    for(auto& v:field){
        cin >> v;
    }
    int ans = 0;
    for(int k=0; k<n; k++){
        bool ok = true;
        for(int i=0; i<n; i++){
            for(int j=1+i; j<n; j++){
                if(field[i][(j+k) % n] != field[j][(i+k) % n]){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        if(ok){
            ans += n;
        }
    }

    cout << ans << "\n";
    return 0;
}