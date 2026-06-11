#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int h,w,j,k;
    cin >> h >> w;
    cin >> j >> k;
    cout << (h*w)-(w*j)-(h*k)+(j*k) << endl;
}