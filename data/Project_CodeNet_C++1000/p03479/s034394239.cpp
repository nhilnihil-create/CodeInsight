#include<iostream>
using namespace std;

int main(){
    long long X,Y;
    cin >> X >> Y;
    long long counta=1;
    while(2*X<=Y){
        counta++;
        X=2*X;
    }
    cout << counta << endl;
    system("pause");
    return 0;
}