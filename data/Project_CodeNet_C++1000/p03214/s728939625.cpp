#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> flames(n);for(int i=0;i<n;i++){cin>>flames[i];}

    long long acc = 0;
    for (auto f : flames){
        acc += f;
    }
    double ave = acc / (double)n;

    vector<double> diff;
    double min_diff = 100000000000000000000.0;
    for (auto f: flames){
        double val = abs(f - ave);
        diff.push_back(val);
        if (val < min_diff){
            min_diff = val;
        }
    }
    int min_index = 0;
    for (int i=0;i<diff.size();i++){
        if (diff[i] == min_diff){
            min_index = i;
            break;
        }
    }
    cout << min_index << endl;
    return 0;
}