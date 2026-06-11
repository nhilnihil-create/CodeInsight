#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin>>a;
    for (int i=0; i<a.size() - 8; i++) {
        cout<<a.at(i);
    }
    cout<<endl;
    return 0;
}