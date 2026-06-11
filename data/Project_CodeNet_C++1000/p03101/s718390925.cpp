#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;
    cout<<h1*w1-h2*w1-h1*w2+h2*w2<<endl;
    return 0;
}