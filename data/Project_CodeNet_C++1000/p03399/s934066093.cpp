#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A , B , C , D ;
    cin >> A >> B >> C >> D ;
    A = fmin(A , B) ;
    C = fmin(C , D) ;
    cout << A + C << endl;
    return 0;
}
