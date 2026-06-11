#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int c=0,d=0;
    for (int i=0; i<s.size(); i++) {
        if (s.at(i)=='R') c++;
        else d++;
    }
    cout<<((c>d) ? "Yes":"No")<<endl;
    return 0;
}
