#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(void){
    int H,W,h,w;
    cin >>H>>W>>h>>w;
    int ans = H*W - h*W - (H-h) * w;
    cout << ans << endl;
}
