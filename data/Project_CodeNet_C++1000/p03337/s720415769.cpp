#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int a, b, c1, c2, c3;

    cin>>a>>b;

    c1 = a+b;
    c2 = a-b;
    c3 = a*b;

    cout<<max(c1, max(c2, c3))<<endl;

    return 0;
}