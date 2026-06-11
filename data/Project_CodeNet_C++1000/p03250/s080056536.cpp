#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int data[3];
    for(int i=0;i<3;i++) cin >> data[i];
    sort(data,data+3,greater<int>());
    cout << data[0] * 10 + data[1] + data[2] <<endl;
}