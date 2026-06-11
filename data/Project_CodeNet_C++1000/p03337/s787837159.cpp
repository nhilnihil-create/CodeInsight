#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    int sum = a+b;
    int sub = a-b;
    int mult = a*b;

    if(sum > sub && sum>mult){
        cout << sum << endl;
    }else if (sub>mult){
        cout << sub << endl;
    }else{
        cout << mult << endl;
    }

    return 0;
}
