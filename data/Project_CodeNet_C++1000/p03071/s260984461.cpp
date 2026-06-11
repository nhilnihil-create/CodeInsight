#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int ans = 0;
    int X = max(A,B);
    int Y = min(A,B);
    ans += X;
    X--;
    ans += max(X,Y);
    cout << ans << endl;
}
