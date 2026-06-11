#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

long long gcd(long long a,long long b)
{
    if (a%b == 0){
        return b;
    }
    else {
        long long r;
        r = a%b;
        return gcd(b,r);
    }
}


int main()
{
    int n;
    long long k;
    long long ans;
    vector<long long> a;
    
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> k;
        a.push_back(k);
    }
    
    sort(a.begin(),a.end());
       
    ans = a[0];
    for (int i = 0;i < a.size();i++){
        ans = gcd(a[i],ans);
    }
    cout << ans << endl;
}
