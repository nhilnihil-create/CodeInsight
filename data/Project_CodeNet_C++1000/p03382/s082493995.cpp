#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;


int main(){
    int n;
    vector<ll> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll aa;
        cin >> aa;
        a.push_back(aa);
    }

    sort(a.begin(), a.end());

    auto itr1 = lower_bound(a.begin(), a.end(), (a[n-1]+2)/2);
    auto itr2 = upper_bound(a.begin(), a.end(), a[n-1]/2);

    if(itr1 == a.begin()){
        cout << a[n-1] << " " << *itr2 << endl;
    }
    else if(itr2 == a.end()-1){
        cout << a[n-1] << " " << *(itr1-1) << endl;
    }
    else{
        itr1--;
        if(a[n-1] - *itr1*2 < *itr2*2 - a[n-1]){
            cout << a[n-1] << " " << *itr1 << endl;
        }
        else{
            cout << a[n-1] << " " << *itr2 << endl;
        }
    }


    return 0;

}
