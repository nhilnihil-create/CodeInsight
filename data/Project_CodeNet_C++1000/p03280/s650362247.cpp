#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int A,B;
    cin >> A >> B;
    int garden = A * B;
    int road = (A + B) - 1;
    cout << (garden - road);
}