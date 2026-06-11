#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    
    vector <int> cnt(4);
    for (int i = 0; i < 3; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        cnt[a]++; cnt[b]++;
    }
    
    bool f = true;
    for (int i = 0; i < 4; i++){
        if (1 <= cnt[i] && cnt[i] <= 2){
        }else{
            f = false;
        }
    }

    if (f == true) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}