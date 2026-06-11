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
    int s;
    cin >> s;
    int left = s/100;
    int right = s%100;
    if((left-1)*(left-12) <= 0 && (right-1)*(right-12) <= 0)cout << "AMBIGUOUS"<<endl;
    else if((left-1)*(left-12) <= 0)cout << "MMYY" << endl;
    else if((right-1)*(right-12) <= 0)cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}
