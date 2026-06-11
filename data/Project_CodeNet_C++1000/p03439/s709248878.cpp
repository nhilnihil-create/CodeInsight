#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;


int main() {
    

    int resLis[ll(1e5)];
    ll n;
    cin >> n;
    string res, preRes;
    cout << 0 << endl;
    cin >> res;
    if(res == "Male"){
        resLis[0] = 1;
    }else{
        resLis[0] = -1;
    }
    if(res == "Vacant") return 0;
    preRes = res;

//    cout << res << endl;
//
    cout << n/2 << endl;
    cin >> res;
    if(res == "Male"){
        resLis[n/2] = 1;
    }else{
        resLis[n/2] = -1;
    }

    if(res == "Vacant") return 0;

//    cout << res << endl;
    ll l,r;
    int preResDir = 0;

    if(preRes == res){
        if((n/2)%2 == 0){
            l = n/2;
            r = n+1;
            preResDir = -1;
        }else{
            l = 0;
            r = n/2;
            preResDir = 1;
        }
    }else{
        if((n/2)%2 == 1){
            l = n/2;
            r = n+1;
            preResDir = -1;
        }else{
            l = 0;
            r = n/2;
            preResDir = 1;
        }
    }
    preRes = res;

    while(res != "Vacant"){
        cout << (l+r)/2 << endl;
        ll m = (l+r)/2;
        cin >> res;
//        cout << res << endl;
        if(res == "Male"){
            resLis[m] = 1;
        }else{
            resLis[m] = -1;
        }

        if(resLis[l] == resLis[m]){
            if((m-l)%2 == 0){
                l = m;
                preResDir = -1;
//                cout << "flag" << endl;
            }else{
                r = m;
                preResDir = 1;
            }
        }else{
            if((m-l)%2 == 1){
                l = m;
                preResDir = -1;
            }else{
                r = m;
                preResDir = 1;
            }
        }
        preRes = res;




    }




}