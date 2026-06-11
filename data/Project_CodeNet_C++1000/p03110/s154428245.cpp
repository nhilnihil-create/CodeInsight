#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    double x[N];
    string y[N];
    
    double total = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> x[i] >> y[i];
        if(y[i] == "JPY"){
            total += x[i];
        }else{
            total += x[i] * 380000.0;
        }
    }
    cout << total << endl;
    return 0;
}