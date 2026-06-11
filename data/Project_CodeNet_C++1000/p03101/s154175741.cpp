#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int H,W,h,w;
    cin>>H>>W>>h>>w;
    //maybe i can do it in a better way
    int tot=H*W;
    int paint=h*W;
    int left=tot-paint;
    int col=left/W;
    int more=col*w;
    cout<<left-more;
}
