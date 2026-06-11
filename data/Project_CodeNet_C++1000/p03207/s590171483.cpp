#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int sum = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        sum += p[i];
        if(max < p[i]) max = p[i];
    }

    cout << sum - max/2 << endl;
    return 0;
}