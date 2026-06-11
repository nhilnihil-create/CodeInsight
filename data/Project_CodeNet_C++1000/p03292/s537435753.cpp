#include <iostream>
using namespace std;

int main() {
    int a,mn=100,mx=0;
    for (int i = 0; i < 3; ++i) {
        cin>>a;
        mn=min(a,mn);
        mx=max(a,mx);
    }
    cout<<mx-mn<<endl;
}
