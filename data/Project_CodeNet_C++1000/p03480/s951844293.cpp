#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    string s;
    cin >> s;
   int ans = s.size();
   for(int i = 0; i < s.size() - 1; ++i){
       if(s[i] != s[i + 1]){
           ans = min(ans, max((int)s.size() - i - 1, i + 1));
       }
   }
   cout << ans;
}