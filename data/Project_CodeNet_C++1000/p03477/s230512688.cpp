#include <iostream>

using namespace std;

int main()
{
    int a ,b ,c ,d;
    cin>>/**<  */ a >> b >> c >> d;
    string result;
    if(a+b > c+d){
       result = "Left" ;
    }else if (a+b < c+d){
    result = "Right";}else { result = "Balanced";}
    cout << result;
    return 0;
}
