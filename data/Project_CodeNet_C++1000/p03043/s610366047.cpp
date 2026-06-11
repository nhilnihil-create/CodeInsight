#include <bits/stdc++.h>

using namespace std;

int main()
{
    double N,K;
    cin >> N >> K;

    double p = 0;

    for(double i=1; i<=N; i++)
    {
        double temp = 1.0 / N ;
        int point = i;
        while(point < K){
            temp *= 0.5;
            point *= 2;
        }
        p += temp;
    }

    cout << fixed << setprecision(12) << p << endl;

    return 0;
}