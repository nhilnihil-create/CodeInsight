#include <iostream>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    if (n==1 && m==1){
        cout << 1 << endl;
        return 0;
    }
    if (n==1 && 2<m){
        cout << m-2 << endl;
        return 0;
    }
    if (m==1 && 2<n){
        cout << n-2 << endl;
        return 0;
    }
    if (3>n || 3>m){
        cout << 0 << endl;
        return 0;
    }
    cout << (n-2) * (m-2) << endl;
    return 0;
}
