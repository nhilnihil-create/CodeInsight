#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a[5] = {};
    for(int i = 0;i < 6;i++){
        int b;
        cin >> b;
        a[b]++;
    }
    sort(a,a+5,greater<int>());
    if(a[0] != 3)cout << "YES";
    else cout << "NO";
}