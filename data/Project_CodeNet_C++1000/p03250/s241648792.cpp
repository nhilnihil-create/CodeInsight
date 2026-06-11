#include<bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,ans=0;
    cin >> A >> B >> C;
    ans=max({A,B,C});
    if(ans==A){
        cout << A*10+B+C; return 0;
    }
    if(ans==B){
        cout << B*10+A+C; return 0;
    }
    if(ans==C){
        cout << C*10+B+A; 
    }
return 0;
}