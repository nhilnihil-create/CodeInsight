#include <iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int minm = 2000;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        sum += m;
        if(minm > m) minm = m;
    }

    cout << n + (x-sum)/minm << endl;
    return 0;
}