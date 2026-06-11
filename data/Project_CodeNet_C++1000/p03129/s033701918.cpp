#include <iostream>
using namespace std;

int main(){
    int n, k;cin >> n >> k;
    int now = 1;
    for (int i = 0; i < k - 1; i++){
        now += 2;
    }if (n >= now){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}