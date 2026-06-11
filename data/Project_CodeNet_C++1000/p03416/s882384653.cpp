#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int count = 0;
    for(int i = a;i <= b;i++){
        if(i / 10000 == i % 10 && (i % 100) / 10 == (i % 10000) / 1000){
            count++;
        }
    }
    cout << count << endl;
}