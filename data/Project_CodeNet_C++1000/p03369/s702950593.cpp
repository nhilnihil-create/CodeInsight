#include <iostream>
using namespace std;

int main() {
    char c;
    int cnt=700;
    for (int i = 0; i < 3; ++i) {
        cin>>c;
        if (c=='o') cnt+=100;
    }
    cout<<cnt<<endl;
}
