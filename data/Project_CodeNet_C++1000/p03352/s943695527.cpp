#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int m = 0;
    for(int i = 1;i < x + 1;i++){
        for(int j = 2;;j++){
            int memo = pow(i, j);
            if(m < memo && memo <= x)m = memo;
            if(x <= memo || i == 1)break;
        }
    }
    cout << m << endl;
}