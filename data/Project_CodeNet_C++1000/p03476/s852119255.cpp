#include <bits/stdc++.h>
using namespace std;

void getprime(vector<int> &prime,int n) {
    prime.push_back(3);
    prime.push_back(5);
    for(int i=11;i<=n;i+=2) {
        int k=0;
        if((((i+1)/2)%2) == 0) {
            k = 1;
        } else {
            for(int j=3;j<=sqrt(i);j+=2) {
                if(i%j==0) {
                    k = 1;
                    break;
                }
                if((((i+1)/2)%j) == 0) {
                    k = 1;
                    break;
                }
            }
        }
        if(k == 0) prime.push_back(i);
    }
}

int main(void) {
    vector<int> prime;
    getprime(prime,(int)1e5);
    
    int Q,l,r;
    cin >> Q;
    vector<int> ans(Q);
    for(int i=0;i<Q;i++) {
        cin >> l >> r;
        vector<int>::iterator itl = lower_bound(prime.begin(), prime.end(), l);
        vector<int>::iterator itr = upper_bound(itl, prime.end(), r);
//        if((*itl) == l) {
            ans[i] =  distance(itl,itr);
//        } else {
//            ans[i] = distance(itl,itr) - 1;
//        }
    }

    for(int i=0;i<Q;i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
