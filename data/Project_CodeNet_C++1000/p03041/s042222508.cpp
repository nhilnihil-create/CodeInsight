#include <iostream>
#include <string>
using namespace std;

int n, karakterkecil;
string input;

int main (){
    cin>>n>>karakterkecil>>input;
    karakterkecil--;
    input [karakterkecil]+=32;
    cout<<input<<endl;
}