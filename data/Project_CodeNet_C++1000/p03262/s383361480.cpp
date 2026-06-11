// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int next(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return x / i;
        }

       
    }
    return 1;
}
int gcd(int a, int b) {
    if (b == 0)return a;

    return gcd(b, a % b);
}
int main()
{
    int n,x;

    cin >> n >> x;
    vector<int> X(n);
    vector<int>sa(n);
    int min = 1000000008;
    for (int i = 0; i < n; i++) {
        cin >> X[i];
 /*       if (min > abs(X[i] - x)) {
            min = abs(X[i] - x);
        }*/
        sa[i] = abs(X[i] - x);
    }
   // bool ok = false;
    //while (ok==false && min > 1) {

    //    for (int i = 0; i < n; i++) {
    //        if (abs(X[i] - x) % min != 0) {
    //            ok = false;
    //            min = next(min);
    //            break;
    //        }
    //        ok = true;
    //    }
    //    
    //}
    int ans =sa[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, sa[i]);
    }

    cout << ans << endl;
    return 0;
}

