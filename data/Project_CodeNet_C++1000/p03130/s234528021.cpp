#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> count(4);
    for(int i=0; i<3; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        count[a] += 1;
        count[b] += 1;
    }
    for(int i=0; i<4; i++){
        if(count[i] == 3){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}