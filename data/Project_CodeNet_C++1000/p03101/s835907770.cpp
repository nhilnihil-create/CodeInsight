#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int h1,h2,w1,w2;
    cin>>h1>>w1>>h2>>w2;
    cout<<(h1-h2)*(w1-w2)<<endl;
    return 0;
}