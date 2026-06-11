#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> ab(m-1);
    for(int i = 0; i < m-1; i++){
        ab[i] = abs(x[i] - x[i+1]);
    }

    sort(ab.begin(), ab.end());
    int sum = 0;
    for(int i = 0; i < m-1-n+1; i++){
        sum += ab[i];
    }
    cout << sum << endl;

    
}