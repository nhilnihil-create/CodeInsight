#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int D, G; cin >> D >> G;
    vector<int> p(D);
    vector<int> c(D);
    vector<int> sum(D, 0);
    int i = 0;
    int answer = pow(10,9);
    while(i < D){
        cin >> p[i];
        cin >> c[i];
        i++;
    }
    i = 0;
    while(i <  (1 << D)) {
        int sum = 0;
        int count = 0;
        int bit = D;
        while (bit >= 0 && sum < G) {
            int k = 0;
            if (1 & (i >> bit)) {
                while(k < p[bit] && sum < G) {
                    sum += (bit+1) * 100;
                    count++;
                    k++;
                }
                if (k == p[bit]) {
                    sum += c[bit];
                }
            }
            bit--;
        }
        if (sum >= G) {
            answer = min(answer, count);
        }
        i++;
    }
    cout << answer << endl;
}
