#include <iostream>

using namespace std;

int main()
{
    int H , W , h , w , s ;
    cin >> H >> W ;
    cin >> h >> w ;
    s = (H-h) * (W-w) ;
    cout << s ;
    return 0;
}
