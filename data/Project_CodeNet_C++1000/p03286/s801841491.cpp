#include <iostream>

using namespace std;

int main() {
    long long int N;
    cin >> N;
    long long int l, r, pow;
    string ans;
    if(N>0) {
        l=0;
        r=1;
        pow=1;
        ans = "1";
        while(N>r) {
            l += pow;
            pow *= 4;
            r += pow;
        }
        bool flag=true;
        while(r-l>1) {
            long long int mid=(r+l)/2;
            if(mid<N) {
                if(flag) {
                    ans += '0';
                    flag=false;
                } else {
                    ans += '1';
                    flag=true;
                }
                l = mid;
            } else {
                if(flag) {
                    ans += '1';
                    flag=false;
                } else {
                    ans += '0';
                    flag=true;
                }
                r = mid;
            }
        }
    } else if (N==0) {
        cout << 0 << endl;
    } else {
        l=-2;
        r=0;
        pow=-2;
        ans = "1";
        while(N<l) {
            r += pow;
            pow *= 4;
            l += pow;
        }
        bool flag=true;
        while(r-l>1) {
            long long int mid=(r+l)/2;
            if(mid>N) {
                if(flag) {
                    ans += '0';
                    flag=false;
                } else {
                    ans += '1';
                    flag=true;
                }
                r = mid;
            } else {
                if(flag) {
                    ans += '1';
                    flag=false;
                } else {
                    ans += '0';
                    flag=true;
                }
                l = mid;
            }
        }
    }

    cout << ans << endl;

    return 0;
    
}