#include <iostream>
#include <vector>

using namespace std;

double getProb (vector<double>& p, int k, int maxK) {
    if(k >= maxK) return 1.0;
    double& memo = p[k];
    if(memo != -1) return memo;
    return memo = 0.5 * getProb(p, 2*k, maxK);
}

int main() {
    int N, K;scanf("%d %d", &N, &K);
    vector<double> p(K, -1.0);
    double pSum = 0.0;
    for(int i = 1; i <= N; i++) {
        pSum += getProb(p, i, K);
    }
    printf("%.12lf", pSum/N);
    return 0;
}
