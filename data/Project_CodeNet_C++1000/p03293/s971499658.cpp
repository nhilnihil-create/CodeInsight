#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    string s;
    string t;
    bool ans=false;
    char tmp;
    cin >> s;
    cin >> t;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s==t){
            ans=true;
            break;
        }else{
            tmp=s[n-1];
            for(int j=n-1; j>=1; j--){
                s[j]=s[j-1];
            }
            s[0]=tmp;
        }
    }

    if(ans==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
