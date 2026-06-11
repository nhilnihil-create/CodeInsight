#include <bits/stdc++.h>
using namespace std;

int rate = 380000;

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    vector<string> u(n);

    for (int i=0;i<n;i++){
        double xi;
        string ui;
        cin >> xi >> ui;
        x[i] = xi;
        u[i] = ui;
    }

    double sum = 0;
    for(int i=0;i<n;i++){
        if(u[i]=="JPY") sum += x[i];
        else sum += x[i]*rate;
    }
    cout << sum <<endl;
    return 0;
}