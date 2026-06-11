#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i,sum;
    double mean,min_dif;
    sum = 0;
    mean = 0.0;

    cin >> n;

    vector<int> a(n);
    vector<double> dif_mean_a(n);
    for(i=0; i<n; i++){
        cin >> a.at(i);
        sum += a.at(i);
    }

    mean = (double)sum / (double)n;
    min_dif = (double)sum;

    for(i=0; i<n; i++){
        dif_mean_a.at(i) = abs( (double)a.at(i) - mean );
        min_dif = min(dif_mean_a.at(i) , min_dif);
    }

    for(i=0; i<n; i++){
        if(min_dif == abs (a.at(i) - mean)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}