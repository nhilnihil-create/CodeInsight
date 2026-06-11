#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;


int main(){
    int n;
    char x;
    string s;
    cin >> x;
    if (x == 'A') cout << 'T' << endl;
    else if (x == 'T') cout << 'A' << endl;
    else if (x == 'C') cout << 'G' << endl;
    else cout << 'C' << endl; 
    return 0;
}