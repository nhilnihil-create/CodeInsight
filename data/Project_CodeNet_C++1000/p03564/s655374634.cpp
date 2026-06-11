#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    int num = 1;
    
    bool judge = true;
    int counter = 0;
    
    while(judge == true){ 
        if(num * 2 > num + K) num += K;
        else num *= 2;
        counter++;
        if(counter == N) judge = false;
    }
    cout << num << endl;
    return 0;
}