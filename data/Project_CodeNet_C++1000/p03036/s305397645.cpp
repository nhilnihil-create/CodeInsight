#include<iostream>

using namespace std;

int main(){
    int x[11];
    int r, d;
    cin >> r >> d >> x[0];
    for (int i = 1; i < 11; i++)
    {
        x[i] = r * x[i - 1] - d;
    }
    for (int i = 1; i < 11; i++)
    {
        cout << x[i] << endl;
    }
    return 0;
}