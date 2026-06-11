#include <bits/stdc++.h>
using namespace std;

int __cd(int a,int b, int k) {
    int maxd = min(a,b);
    int cnt = 0;
    for(int i=maxd;i>0;i--) {
        if(a%i==0 && b%i==0) {
            cnt++;
            if(cnt == k){
                return i;
            }
        }
    }
    return 1;
}

int main(void) {
    int A,B,K;
    
    cin >> A >> B >> K;
    cout << __cd(A,B,K) << endl;

    return 0;
}
