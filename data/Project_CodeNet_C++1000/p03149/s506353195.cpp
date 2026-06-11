#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> N;
    int sum = 0;
    bool flag = true;
    for(int i = 0; i < 4; i++){
        int n; cin >> n;
        sum += n;
        if(n != 1 && n != 4 && n != 7 && n != 9){
            flag = false;
        }
    }
    if(flag){
        if(sum == 21) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
}