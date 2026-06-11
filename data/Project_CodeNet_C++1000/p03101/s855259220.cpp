#include<iostream>
using namespace std;
int main()
{
    int H,W,h,w;
    cin >> H >> W;
    cin >> h >> w;
    if(H>=1 && W<=20 && h>=1 && H>=h && w>=1 && W>=w)
    {
        int result = (H-h)*(W-w);
        cout << result << endl;
    }
    return 0;
}
