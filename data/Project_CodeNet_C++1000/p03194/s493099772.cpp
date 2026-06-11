//
// Created by Geoffrey West on 12/22/18.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long int N = 10000000;
int lp[N+1];
vector<int> pr;


int main() {
    unsigned long long int n, p;
    cin >> n >> p;
    int d[1000000] = {0};
    if (n == 1){
        cout << p << endl;
        return 0;
    }
    long long int op = p;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    int i = 0;
    while (p != 1 && i < pr.size()) {
        if (p % pr[i] == 0) {
            d[i]++;
            p /= pr[i];
        } else {
            i++;
        }
    }
    int res = 1;
    for(int j = 0; j < pr.size(); j++)
    {
        res *= pow(pr[j], d[j]/n);
    }
    cout << res << endl;
    return 0;
}