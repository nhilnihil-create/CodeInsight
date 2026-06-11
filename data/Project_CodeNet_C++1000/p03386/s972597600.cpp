#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    for(int i = a;i < b + 1;i++){
        if(a <= i && i <= a + k - 1)cout << i << endl;
        else if(b - k + 1<= i && i <= b)cout << i << endl;
    }
}