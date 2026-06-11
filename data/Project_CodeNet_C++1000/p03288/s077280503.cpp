#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if(N >= 2800)
    {
        cout << "AGC";
    }
    else if(N >= 1200)
    {
        cout << "ARC";
    }else
    {
        cout <<"ABC";
    }
}