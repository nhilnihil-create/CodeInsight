#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,D,x[11];
    cin >> r >> D >> x[0];
    for (int i = 1;i <= 10; i++)
    {
        x[i] = r*x[i-1] - D;
        cout << x[i] << endl;
    }
    
}