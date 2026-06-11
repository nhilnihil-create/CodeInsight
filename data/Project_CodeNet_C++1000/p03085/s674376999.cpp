#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
using namespace std;

const unsigned long long BASE = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

int main()
{
    char b;
    cin >> b;
    if (b == 'A')
        cout << 'T' << endl;
    else if (b == 'T')
        cout << 'A' << endl;
    else if (b == 'C')
        cout << 'G' << endl;
    else if (b == 'G')
        cout << 'C' << endl;
    return 0;
}
