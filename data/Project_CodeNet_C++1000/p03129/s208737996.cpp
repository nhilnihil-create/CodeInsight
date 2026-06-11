#include <iostream>
using namespace std;

int main(){
    int n, k;cin>>n>>k;
    int num;
    if (n % 2 == 0){
        num = n / 2;
    } else {
        num = (n+1)/2;
    }
    if (num >= k){
        cout << "YES" <<endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}