#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 111;
    for(int i=0; i<9; i++){
        if(n <= ans){
            cout << ans << endl;
            return 0;
        }
        ans += 111;
    }
    return 0;
}