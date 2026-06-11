#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    double x, JPY_sum=0, BTC_sum=0;
    string u;

    for(int i=0; i<N; i++){
        cin >> x >> u;
        if(u[0]=='J') JPY_sum += x;
        else BTC_sum += x;
    }

    double sum = 380000.00000000 * BTC_sum;

    sum += JPY_sum;

    printf("%.7lf\n", sum);

    return 0;
}