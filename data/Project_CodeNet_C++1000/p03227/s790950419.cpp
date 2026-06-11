#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
using namespace std;

int main(){
string s;cin>>s;
if(s.length()==2)cout<<s;
else cout<<string(rbegin(s),rend(s));
}
