#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(5);
    int N;
    cin >> N;
    vector<double>x(N);
    vector<string>u(N);
    double sum=0;
    for(int i=0;i<N;i++){
        cin >> x.at(i);
        cin >> u.at(i);
        if(u.at(i)=="JPY")sum+=x.at(i);
        else sum+=x.at(i)*380000;
    }
    cout << sum << endl;

}