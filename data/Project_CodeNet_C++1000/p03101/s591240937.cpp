#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)

int getmd(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}

int main(){
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    cout << h*w-(x*w+y*h-x*y) << endl;

    return 0;
}