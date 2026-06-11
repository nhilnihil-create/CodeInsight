#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
int main()
{
    int N,M;
    cin >> N >> M;
    cout << max(N+M,max(N-M,N*M));
}