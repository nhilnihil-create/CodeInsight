#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
int main()
{
    int month,date;
    cin >> month >> date;
    cout << (date >= month ? month : month - 1);  
}