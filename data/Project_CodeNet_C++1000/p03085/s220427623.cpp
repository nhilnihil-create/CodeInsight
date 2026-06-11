#include <bits/stdc++.h>

using namespace std;

int main(){
    string b,bondPair;
    cin>>b;
    if(b=="A")bondPair="T";
    if(b=="T")bondPair="A";
    if(b=="C")bondPair="G";
    if(b=="G")bondPair="C";
    cout<<bondPair;
}
