#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int s;
    int fx = 0;//整数の位の和
    int n;
    int m;
    cin >> N;
    n = N;//入力された整数値を保持//
    m = N;
    while(!(N == 0)){
        s++;
        N = N/10;
    }
    for(int i=0;i<s;i++){
        fx = fx + n%10;
        n = n/10;
    }
    if(m%fx == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}