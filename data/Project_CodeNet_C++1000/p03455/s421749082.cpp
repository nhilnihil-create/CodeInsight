#include <iostream>

using namespace std;

int main()
{
    int a ,b;
    cin >> a >> b;
    string result ;
    if(a%2==0 || b%2==0 ){
        result = "Even";
    }else {
    result = "Odd";}
    cout << result;
    return 0;
}
