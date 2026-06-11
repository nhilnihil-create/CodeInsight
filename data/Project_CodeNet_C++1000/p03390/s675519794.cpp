#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

long long bins (long long k, long long l, long long r){
    long long q = (r+l) / 2;
    long long qq = r * r;
    //cout << l << ' ' << r << '\n';
    if (r - l <= 1){
        if (qq >= k){
            return l;
        }
        else{
            return r;
        }
    }
    else{
        qq = q*q;
        if (qq >= k){
            return bins (k, l, q-1);
        }
        else {
            return bins (k, q, r);
        }
    }
}

int main() {
    long long n,a,b;
    cin >> n;
    vector <long long> ans;
    for (int i = 0; i<n; i++){


        cin >> a >> b;
        long long k = min (a,b);
        long long q = max (a,b);
        a = k;
        b = q;
        if (b - a <= 1){
            ans.push_back(2*(a-1));
            //cout << 2*(a-1) << '\n';
        }
        else{
            k = a*b;
            q = bins (k, a, b);
            long long ss = min (a,b);
            long long k1, k2;
            k2 = 2*(ss-1);
            k1 = 2*(ss-1);
            k1 += 2*(q - a);
            if (q * (q+1) < k){
                k2 += 2 * (min ((q-a),(b-q-1)) + 1) - 1;
            }
            ss = max(k1, k2);
            ans.push_back(ss);
            //cout << ss << '\n';
        }
    }
    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}