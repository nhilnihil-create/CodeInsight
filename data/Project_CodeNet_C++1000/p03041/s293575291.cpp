#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string inp;
    int n, k;
    cin >>k>> n >> inp;
    inp[n-1] = tolower(inp[n-1]);
    cout<< inp;
    return 0;
}
