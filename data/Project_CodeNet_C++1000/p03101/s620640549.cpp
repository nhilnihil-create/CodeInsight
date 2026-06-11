#include<iostream>
using namespace std;

int main(void){
    int H, W, h, w, count;
    cin >> H >> W >> h >> w;

    count = H * W - h * W - H * w + h * w;
    cout << count << endl;
    return 0;
}