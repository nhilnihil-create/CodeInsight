#include <iostream>

using namespace std;

int main() {
    long long int N;
    cin >> N;
    
    long long int r=0;
    long long int l=0;
    long long int p;
    string ans;
    if(N>r) {
        r = 1;
        p = 1;
        while(r<=N) {
            r += p;
            p *= 4;
        }
        l = r-p/4;
    } else if(N<l) {
        l = -1;
        p = 2;
        while(l>=N) {
            l -= p;
            p *= 4;
        }
        r = l+p/4;
    }
    
    if(r-l<1) {
        ans = "0";
    } else {
        ans = "1";
    }

    bool flag= N>0 ? true : false;
    while(r-l>1) {
        long long int mid=(r+l)/2;
        
        if(N>0) {
            if(N<mid) {
                r = mid;
                if(flag) {
                    ans += "1";
                    flag = false;
                } else {
                    ans += "0";
                    flag = true;
                }
            } else {
                l = mid;
                if(flag) {
                    ans += "0";
                    flag = false;
                } else {
                    ans += "1";
                    flag = true;
                }
            }
        } else {
            if(N<=mid) {
                r = mid;
                if(flag) {
                    ans += "1";
                    flag = false;
                } else {
                    ans += "0";
                    flag = true;
                }
            } else {
                l = mid;
                if(flag) {
                    ans += "0";
                    flag = false;
                } else {
                    ans += "1";
                    flag = true;
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
    
}