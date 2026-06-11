#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++){
        if (s.at(i)=='x') c++;
    }
    cout<<((c>7) ? "NO":"YES")<<endl;
    return 0;
}