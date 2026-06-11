#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s.at(k-1) = s.at(k-1)-('A'-'a');
    cout << s << endl;
}
