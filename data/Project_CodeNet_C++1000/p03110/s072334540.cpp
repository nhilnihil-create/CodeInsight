#include <bits/stdc++.h>
using namespace std;
const double BTCtoJPY = 380000.0;
int main(){
    int N;
    cin >> N;
    double sum;
    for(int i=0;i<N;i++){
        double value;
        string type;
        cin >> value >> type;
        sum += (type=="BTC" ? value*BTCtoJPY : value);
    }
    cout << sum;
    return 0;
}