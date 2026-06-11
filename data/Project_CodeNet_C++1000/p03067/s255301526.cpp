#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
int a,b,c;cin>>a>>b>>c;
if(c>=b&&c<=a&&b<a)cout<<"Yes";
else if(c>=a&&c<=b&&b>a)cout<<"Yes";
else cout<<"No";
}