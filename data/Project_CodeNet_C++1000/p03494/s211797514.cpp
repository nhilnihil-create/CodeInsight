#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int>vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at (i);
    }
    double  sum=0.0;
    
    while (true) {
        for (int i=0; i<N; i++) {
            if (vec.at(i)%2==0) {
                sum+=1.0/(N+0.0);
                vec.at(i)/=2;
            }
            else {
                sum-=(i+0.0)/(N+0.0);
                goto OUT;
            }
        }
    }
OUT:
    cout << sum << endl;
}
    

                
                
                
