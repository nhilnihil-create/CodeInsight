#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using lint = long long;


int main(){
    string s,l;
    int w;
    cin>>s>>w;
    for (int i=0; i*w<s.size(); i++) {
        l += s.at(i*w);
    }
    cout<<l<<endl;
    return 0;
}