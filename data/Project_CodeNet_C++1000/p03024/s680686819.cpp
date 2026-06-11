#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    string s;cin>>s;
    int n=0;
    for(char x:s)if(x=='x')n++;
    if(n<=7)cout<<"YES";
    else cout<<"NO";
}
