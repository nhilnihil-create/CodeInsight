#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int data[3];
    int sum = 0;
    for(int i=0;i<3;i++) cin >> data[i];
    
    sort(data,data+3);
    //sum += data[0];
    for(int i=1;i<3;i++){
        sum += abs(data[i] - data[i-1]);
    }
    cout << sum <<endl;
}