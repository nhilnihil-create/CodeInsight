#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> count(4,0);

    for(int i = 0; i < 6; i++){
        int a;
        cin >> a;
        a--;
        count[a]++;
    }

    int num = 0;

    for(int i = 0; i < 4; i++){
        if(count[i] == 1){
            num++;
        }
    }

    string result = "NO";
    if(num == 2) result = "YES";

    cout << result << endl;
    return 0;
}