#include<iostream>
using namespace std;
int main(void){
    int d = 0;
    cin >> d;
    string s = "Christmas";
    for (int i = 25; i > d; i--)
    {
        s += " Eve";
    }
    cout << s;
}