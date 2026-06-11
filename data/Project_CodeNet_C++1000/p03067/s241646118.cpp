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
    int a,b,c;cin>>a>>b>>c;
    if(a>b)swap(a,b);
    if(c<=b&&c>=a)cout<<"Yes";
    else cout<<"No";
}