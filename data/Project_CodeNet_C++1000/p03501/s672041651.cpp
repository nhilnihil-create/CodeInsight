#include<iostream>
using namespace std;
int main()
{
    int N, A, B, ans;
    cin >> N >> A >> B;
    ans = A * N;
    if(B < ans)
    {
        ans = B;
    }
    cout << ans << endl;
}