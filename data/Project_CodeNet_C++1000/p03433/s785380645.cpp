#include <iostream>

using namespace std;

int main()
{
    int n ,a;
    cin >> n >>a;
    string result;
    if (n%500 > a){
        result = "No";
    }else {
    result ="Yes";}
    cout << result;
    return 0;
}
