
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

void testcase(){
    int n,k;
    cin>>n>>k;
    k--;
    string s;
    cin>>s;
    s[k] += 32;    
    cout << s << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}