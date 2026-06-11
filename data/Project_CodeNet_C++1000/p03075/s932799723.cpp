#include <iostream>

using namespace std;

int main()
{
    int a , b , c , d , e , k;
    cin>> a ;
    cin>> b ;
    cin>> c ;
    cin>> d ;
    cin>> e ;
    cin>> k ;
    if (e-a <= k) {
        if (d-a <= k) {
            if (c-a <= k) {
                if (b-a <= k) {
                    if (e-b <= k) {
                        if (d-b <= k) {
                            if (c-b <= k) {
                                if (e-c <= k) {
                                    if (d-c <= k) {
                                        if (e-d <= k) {
                                            cout<< "Yay!";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        cout<< ":(";
    }
    return 0;
}
