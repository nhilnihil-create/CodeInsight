#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,h,W,w;
    cin >> H >> W >> h >> w;

    int nokori;
    nokori = H*W;

    nokori -= h*W;
    nokori -= w*(H-h);

    cout << nokori << endl;
}