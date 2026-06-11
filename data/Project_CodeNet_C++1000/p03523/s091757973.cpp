#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    string S;

    cin >> S;

    if(S=="KIHBR") cout << "YES" << endl;
    else if(S=="AKIHBR") cout << "YES" << endl;
    else if(S=="KIHABR") cout << "YES" << endl;
    else if(S=="KIHBAR") cout << "YES" << endl;
    else if(S=="KIHBRA") cout << "YES" << endl;
    else if(S=="AKIHABR") cout << "YES" << endl;
    else if(S=="AKIHBAR") cout << "YES" << endl;
    else if(S=="AKIHBRA") cout << "YES" << endl;
    else if(S=="KIHABAR") cout << "YES" << endl;
    else if(S=="KIHABRA") cout << "YES" << endl;
    else if(S=="KIHBARA") cout << "YES" << endl;
    else if(S=="AKIHABAR") cout << "YES" << endl;
    else if(S=="AKIHABRA") cout << "YES" << endl;
    else if(S=="AKIHBARA") cout << "YES" << endl;
    else if(S=="KIHABARA") cout << "YES" << endl;
    else if(S=="AKIHABARA") cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}