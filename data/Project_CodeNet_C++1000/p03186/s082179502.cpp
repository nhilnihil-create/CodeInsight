#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(C<=A){
        cout << C+ B << endl;
    }
    else{
        if(A+B>=C) cout << B+C << endl;
        else{
            cout << A+B+B+1 << endl;
        }
    }


    return 0;
}
