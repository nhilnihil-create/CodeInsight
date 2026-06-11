#include <bits/stdc++.h>

using namespace std;

int main() {
    /* code */
    int N = 0;
    cin >> N;
    int ans = 100000;
    int A, B, C, D, E;
    int temp = 0;
    for (size_t i = 1; i < 1+N/2; i++)
    {
        temp = 0;
        A = i;
        B = N - i;
        while (A!=0)
        {
            temp += A%10;
            A /= 10;
        }while (B!=0)
        {
            temp += B%10;
            B /= 10;
        }
        //cout << temp << endl;
        if(ans > temp){
            ans = temp;
        }
    }
    cout << ans << endl;
    

    return 0;
}