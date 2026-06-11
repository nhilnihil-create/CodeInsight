#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string ABCD;
    cin >> ABCD;
    int total = 0;
    int A= (int)ABCD[0]-(int)'0';
    int B =(int)ABCD[1]-(int)'0';
    int C =(int)ABCD[2]-(int)'0';
    int D =(int)ABCD[3]-(int)'0';
    if( (A+B+C+D)==7){
        cout<< A << "+" << B << "+" << C << "+" << D <<"=7" << endl;
    }
    else if( (A+B+C-D)==7){
        cout<< A << "+" << B << "+" << C << "-" << D <<"=7" << endl;
    }
    else if( (A+B-C+D)==7){
        cout<< A << "+" << B << "-" << C << "+" << D <<"=7" << endl;
    }
    else if( (A+B-C-D)==7){
        cout<< A << "+" << B << "-" << C << "-" << D <<"=7" << endl;
    }
    else if( (A-B+C+D)==7){
        cout<< A << "-" << B << "+" << C << "+" << D <<"=7" << endl;
    }
    else if( (A-B+C-D)==7){
        cout<< A << "-" << B << "+" << C << "-" << D <<"=7" << endl;
    }
    else if( (A-B-C+D)==7){
        cout<< A << "-" << B << "-" << C << "+" << D <<"=7" << endl;
    }
    else if( (A-B-C-D)==7){
        cout<< A << "-" << B << "-" << C << "-" << D <<"=7" << endl;
    }
}