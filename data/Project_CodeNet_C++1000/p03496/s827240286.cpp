#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long int> a(N);
    long long int mx=-1e9, mn=1e9;
    int ix=0, in=0;
    int flag=0;
    bool is_unified=true;
    for(int n=0; n<N; n++) {
        cin >> a[n];
        if(a[n]>mx) ix=n;
        if(a[n]<mn) in=n;
        mx = max(mx, a[n]);
        mn = min(mn, a[n]);
        if((flag==1 && a[n]<0) || (flag==-1 && a[n]>0)) {
            is_unified = false;
        } else if(flag==0) {
            if(a[n]<0) {
                flag=-1;
            } else if(a[n]>0) {
                flag=1;
            }
        }
    }
    if(flag==0) {
        cout << 0 << endl;
    } else {
        if(is_unified) {
            cout << N-1 << endl;
            if(flag==1) {
                for(int n=1; n<N; n++) {
                    cout << n << " " << n+1 << endl;
                }
            } else {
                for(int n=N; n>1; n--) {
                    cout << n << " " << n-1 << endl;
                }
            }
        } else {
            cout << (N-1)*2 << endl;
            if(abs(mx)>abs(mn)) {
                for(int n=1; n<=N; n++) {
                    if(n==ix+1) continue;
                    cout << ix+1 << " " << n << endl;
                }
                for(int n=1; n<N; n++) {
                    cout << n << " " << n+1 << endl;
                }
            } else {
                for(int n=1; n<=N; n++) {
                    if(n==in+1) continue;
                    cout << in+1 << " " << n << endl;
                }
                for(int n=N; n>1; n--) {
                    cout << n << " " << n-1 << endl;
                }
            }
        }
    }


    return 0;
    
}