#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    int a = num / 100, b = num % 100;
    if(a && b)
    {
        if(a > 12 && b > 12)
        {
            cout << "NA" << endl;
        }
        else if(a > 12 && b <= 12 && b)
        {
            cout << "YYMM" <<endl;
        }
        else if(a <= 12 && b > 12 && a)
        {
            cout << "MMYY" << endl;
        }
        else if(a <= 12 && b <= 12)
        {
                cout << "AMBIGUOUS" << endl;           
        }
    }
    
    else
    {
        if(a)
        {
            if(a > 12)
            {
                cout << "NA" << endl;
            }
            else if(a <= 12)
            {
                cout << "MMYY" << endl;
            }
        }
        if(b)
        {
            if(b > 12)
            {
                cout << "NA" << endl;
            }
            if(b <= 12)
            {
                cout << "YYMM" << endl;
            }
        }
        if(!a && !b)
        {
            cout << "NA" << endl;
        }
    }
    
    return 0;
}