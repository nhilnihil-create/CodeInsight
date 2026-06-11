#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
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

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    cin >> n;
    vector<LL> t(n, 0);
    vector<LL> c(n-1);
    vector<LL> s(n-1);
    vector<LL> f(n-1);

    for(int i=0; i<n-1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++){
            if(s[i]>t[j]){
                t[j]=s[i];
            }else{
                if(t[j]%f[i]!=0){
                    t[j]+=(f[i]-t[j]%f[i]);
                }
            }
            t[j]+=c[i];
        }
        //for(int j=0; j<n; j++){
        //    cout << t[j] << endl;
        //}
    }

    for(int i=0; i<n; i++){
        cout << t[i] << endl;
    }

    return 0;
}
