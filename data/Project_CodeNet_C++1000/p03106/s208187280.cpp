#include <bits/stdc++.h>

using namespace std;



int main(int argc, char *argv[])
{


    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int A, B, K, cnt = 0;
    cin >> A >> B >> K;
    
    if (A > B) {
        swap(A,B);
    }
    
    for (int i = A; i > 0; i--) {
        if (A % i == 0 && B % i == 0) {
            cnt++;
            if (cnt == K) {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}
