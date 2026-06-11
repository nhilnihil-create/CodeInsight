#include <iostream>

using namespace std;

int main()
{
    int A , B , C , x ;
    cin>> A , cin>> B , cin>> C;
    if ( B/A > 0 ){
        x = B/A;
        if ( x>C ) {
            cout<< C;
        }
        else {
            cout<< x;
        }
    }
    else {
        cout<< 0;
    }
    return 0;
}
