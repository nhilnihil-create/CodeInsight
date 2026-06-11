#include <iostream>

using namespace std;

int main()
{
    char o,x;
    string s;
    cin >>s;
    if(s=="oxx" || s=="xox" || s=="xxo"){
        cout << 800;
    } else if (s=="xxx"){
    cout <<700;
    }else if(s=="oox" || s=="oxo" || s=="xoo"){
    cout <<900;
    }else {
    cout <<1000;}
    return 0;
}
