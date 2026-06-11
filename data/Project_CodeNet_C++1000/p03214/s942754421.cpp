#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    double n;
    cin >>n;
    vector<double> a(n);
    rep(i,n) cin >> a[i];

    double av;
    
    double sum = 0;
    rep(i,n) sum += a[i];
    av = sum/n;

    int min = 0;
    double tmp = (double)abs(a[0]-av);
    rep(i,n){
        if(tmp > (double)abs(av - a[i])){
            min = i;
            tmp = (double)abs(av - a[i]);
        }
    }

    cout << min << endl;
    return 0;
}