#include <iostream>

using namespace std;

int main()
{
    int a ,b ,c;
    cin >>a>>b>>c;
    string result;
    if(a+b >= c){
        result = "Yes" ;
    }else {
    result = "No";}
    cout << result;
    return 0;
}
