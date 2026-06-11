#include<iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    S.erase(3, 1);
    S.insert(3, "8");
    cout << S << endl;
}
