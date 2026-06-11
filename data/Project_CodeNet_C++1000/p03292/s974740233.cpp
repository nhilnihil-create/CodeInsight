#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int ans = 0;
    vector<int> a(3);
    cin >> a.at(0) >> a.at(1) >> a.at(2);
    sort(a.begin(), a.end());
    cout << a.at(2) - a.at(0) << endl;
    return 0;
}