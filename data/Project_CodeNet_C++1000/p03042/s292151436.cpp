#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int s;
    cin >> s;
    int L = s/100;
    int R = s-100*L;
    if (L >= 1 && L <= 12)
    {
        if (R >= 1 && R <= 12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }else
    {
        if (R >= 1 && R <= 12) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }    
}