#include <iostream>

using namespace std;

int main()
{
  
    int A , B,C ;
    cin >> A >> B >> C ;
    if ((A>=1 && A<=500) && (B>=1 && B <= 500)) {
            if (C>=1 && C<=1000){
                if (C<=(A+B)) {
                cout << "Yes" << endl ;
                }
                else
                cout << "No" << endl ;
            }
    }

    return 0;
}
