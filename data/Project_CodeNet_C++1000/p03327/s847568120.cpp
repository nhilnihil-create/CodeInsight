#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
int main()
{
    int N;
    cin >> N;
    cout << ((N > 999) ? "ABD" : "ABC");
}