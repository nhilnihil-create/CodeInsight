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
    int n;cin>>n;
    string s;cin>>s;
    sort(s.begin(),s.end());
    int x=upper_bound(s.begin(),s.end(),'B')-s.begin();
    if(n-x>x)cout<<"Yes";
    else cout<<"No";
}