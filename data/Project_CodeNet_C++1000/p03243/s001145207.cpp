#include <iostream>
using namespace std;
bool check(int x){
    int value = x%10;
    while(x){
        if(x%10 != value){
            return false;
        }
        x /= 10;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    for(int i = N;;++i){
        if(check(i)){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}