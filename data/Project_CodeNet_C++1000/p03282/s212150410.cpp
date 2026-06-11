#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
using namespace std;
int main() {
    string s;
    cin>>s;
    long k;
    cin>>k;
    bool flg=false;
    for (int i=0; i<k; i++){
        if(s[i]!='1'){cout<<s[i];flg=true;break;}
    }
    if(flg==false)cout<<1;
    return 0;
}