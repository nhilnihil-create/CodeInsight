#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(void){
    int A,B,C;
    cin>>A>>B>>C;
    int ans = min(C,B/A);
    cout <<ans;
}
