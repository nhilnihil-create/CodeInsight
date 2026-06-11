#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int H,W;
    cin>>H>>W;
    int h,w;
    cin>>h>>w;
    int x;
    int y;
    int v;
    int z;
    x = H*W;
    y = h*w;
    z = H*w;
    v = W*h;
    cout<<x-z-v+y<<endl;
}